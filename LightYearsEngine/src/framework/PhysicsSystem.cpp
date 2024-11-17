#include "framework/PhysicsSystem.h"
#include "framework/Actor.h"
#include "framework/MathUtility.h"
#include <box2d/b2_body.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>


using namespace std;

namespace ly
{
	unique<PhysicsSystem> PhysicsSystem::physicsSystem{ nullptr };

	PhysicsSystem& PhysicsSystem::Get()
	{
		if (!physicsSystem)
		{
			physicsSystem = move(unique<PhysicsSystem>{new PhysicsSystem});
		}

		return *physicsSystem;
	}

	// constructor no gravity with cm scale
	PhysicsSystem::PhysicsSystem() :
		m_PhysicsWorld{ b2Vec2{0.f, 0.f} },
		m_PhysicsScale{ 0.01f },
		m_VelocityIterations{ 8 },
		m_PositionIterations{ 3 }
	{

	}

	void PhysicsSystem::Step(float dt)
	{
		m_PhysicsWorld.Step(
			dt,
			m_VelocityIterations,
			m_PositionIterations
		);

	}

	b2Body* PhysicsSystem::AddListener(Actor* listener)
	{
		if (listener->IsPendingDestroy())
		{
			return nullptr;
		}

		b2BodyDef bodyDef{};
		bodyDef.type = b2_dynamicBody;

		bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(listener);
		bodyDef.position.Set(
			listener->GetActorLocation().x * GetPhysicsScale(),
			listener->GetActorLocation().y * GetPhysicsScale()
			);

		bodyDef.angle = DegreesToRadians(listener->GetActorRotation());

		b2Body* body = m_PhysicsWorld.CreateBody(&bodyDef);

		b2PolygonShape shape;
		auto bounds = listener->GetActorGlobalBounds();

		shape.SetAsBox(
			(bounds.width / 2.f) * GetPhysicsScale(),
			(bounds.width / 2.f) * GetPhysicsScale()
		);

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &shape;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;
		fixtureDef.isSensor = true;

		body->CreateFixture(&fixtureDef);

		return body;
	}


}
#include "framework/PhysicsSystem.h"



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

	// no gravity with cm scale
	PhysicsSystem::PhysicsSystem() :
		m_PhysicsWorld{ b2Vec2{0.f, 0.f} },
		m_PhysicsScale{0.01f}
	{

	}
}
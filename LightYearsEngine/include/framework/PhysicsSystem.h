#pragma once
#include "framework/Core.h"
#include "framework/Actor.h"
#include <box2d/b2_world.h>

namespace ly
{
	class PhysicsSystem
	{
	public:
		static PhysicsSystem& Get();
		void Step(float dt);

		b2Body* AddListener(Actor* listener);
		float GetPhysicsScale() const { return m_PhysicsScale; }

	protected:
		PhysicsSystem();

	private:
		static unique<PhysicsSystem> physicsSystem;
		b2World m_PhysicsWorld;
		float m_PhysicsScale;
		int m_VelocityIterations;
		int m_PositionIterations;


	};


}
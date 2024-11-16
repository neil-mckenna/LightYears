#pragma once

#include "framework/Actor.h"


using namespace std;
using namespace sf;

namespace ly
{
	class SpaceShip : public Actor
	{
	public:
		SpaceShip(World* owningWorld, const string& texturePath = "");
		virtual void Update(float dt) override;
		void SetVelocity(const Vector2f& newVelocity);
		Vector2f GetVelocity() const { return m_Velocity; }
		virtual void Shoot();

	private:
		Vector2f m_Velocity;

	};

}
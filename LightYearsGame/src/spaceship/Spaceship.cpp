
#include "spaceship/Spaceship.h"

namespace ly
{
	SpaceShip::SpaceShip(World* owningWorld, const string& texturePath) :
		Actor{owningWorld, texturePath},
		m_Velocity{}
	{

	}

	void SpaceShip::Update(float dt)
	{
		Actor::Update(dt);
		AddActorLocationOffset(GetVelocity() * dt);

	}

	void SpaceShip::SetVelocity(const Vector2f& newVelocity)
	{
		m_Velocity = newVelocity;
	}
}


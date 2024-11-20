
#include "spaceship/Spaceship.h"
#include <functional>

namespace ly
{


	SpaceShip::SpaceShip(World* owningWorld, const string& texturePath)
		:
		Actor{ owningWorld, texturePath },
		m_Velocity{},
		m_HealthComponent(new HealthComponent(100.0f, 100.0f))
	{
		m_HealthComponent->SetSpaceShip(this);
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

	void SpaceShip::Shoot()
	{

	}
	void SpaceShip::BeginPlay()
	{
		LOG("Spaceship Begin Play called");
		Actor::BeginPlay();

		SetEnablePhysics(true);

		auto ship = std::shared_ptr<SpaceShip>(m_HealthComponent->GetSpaceShip());

		m_HealthComponent->OnHealthChanged.BindAction(ship, &SpaceShip::OnHealthChanged);
		m_HealthComponent->OnHealthChanged.Broadcast(11, 89, 100);

	}

	void SpaceShip::OnHealthChanged(float amt, float health, float maxHealth)
	{
		LOG("health changed by: %f, and is now: %f / %f", amt, health, maxHealth);
	}


}


#pragma once

#include "framework/Actor.h"
#include "gameplay/HealthComponent.h"


using namespace std;
using namespace sf;

namespace ly
{
	class HealthComponent;

	class SpaceShip : public Actor
	{
	public:
		SpaceShip(World* owningWorld, const string& texturePath = "");
		virtual void Update(float dt) override;
		void SetVelocity(const Vector2f& newVelocity);
		Vector2f GetVelocity() const { return m_Velocity; }
		virtual void Shoot();
		virtual void BeginPlay() override;

	private:
		void OnHealthChanged(float amt, float health, float maxHealth);
		Vector2f m_Velocity;

		HealthComponent* m_HealthComponent;
	};

}
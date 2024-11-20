#pragma once

#include "framework/Core.h"
#include "framework/Delegate.h"
#include <spaceship/Spaceship.h>

namespace ly
{
	class SpaceShip;

	class HealthComponent
	{

	public:


		HealthComponent(float health, float maxHealth);

		void SetSpaceShip(SpaceShip* spaceShip);
		SpaceShip* GetSpaceShip();

		void ChangeHealth(float amt);
		float GetHealth() { return m_Health; }
		float GetMaxHealth() { return m_MaxHealth; }

		Delegate<float, float, float> OnHealthChanged;

		~HealthComponent();

	private:
		float m_Health;
		float m_MaxHealth;

		void TakenDamage(float amt);
		void HealthEmpty();
		void HealthRegen(float amt);

		SpaceShip* m_SpaceShip;
	};



}
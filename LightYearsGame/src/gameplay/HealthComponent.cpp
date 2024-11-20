#include "gameplay/HealthComponent.h"
#include "spaceship/Spaceship.h"

namespace ly
{
    // Constructor
    HealthComponent::HealthComponent(float health, float maxHealth)
        : m_Health(health), m_MaxHealth(maxHealth), m_SpaceShip(nullptr)
    {
    }

    void HealthComponent::SetSpaceShip(SpaceShip* spaceShip)
    {
        m_SpaceShip = spaceShip;
    }

    SpaceShip* HealthComponent::GetSpaceShip()
    {
        return m_SpaceShip;
    }


    // Change the health by a certain amount
    void HealthComponent::ChangeHealth(float amt)
    {
        LOG("Change health called");

        // No change if amount is zero or health is already zero
        if (amt == 0 || m_Health == 0) {
            return;
        }

        m_Health += amt;

        // Clamp health to a minimum of 0
        if (m_Health < 0)
        {
            m_Health = 0;
        }

        // Clamp health to the maximum value
        if (m_Health > m_MaxHealth)
        {
            m_Health = m_MaxHealth;
        }

        // If the change is negative, process damage
        if (amt < 0)
        {
            TakenDamage(-amt); // Call TakenDamage with positive amount
            if (m_Health <= 0)
            {
                HealthEmpty();
            }
        }
        else
        {
            HealthRegen(amt); // Process health regeneration
        }
    }

    // Handle damage
    void HealthComponent::TakenDamage(float amt)
    {
        LOG("Took Damage %f now health is: %f / %f", amt, m_Health, m_MaxHealth);
    }

    // Handle health reaching zero
    void HealthComponent::HealthEmpty()
    {
        LOG("Dead!");
    }

    // Handle health regeneration
    void HealthComponent::HealthRegen(float amt)
    {
        LOG("Health Regening %f now health is: %f / %f", amt, m_Health, m_MaxHealth);
    }

    // Destructor
    HealthComponent::~HealthComponent()
    {
        // Clean up resources if needed
    }
}

#pragma once

#include <SFML/System.hpp>
#include "weapon/Shooter.h"

using namespace sf;
using namespace std;

namespace ly
{
	class BulletShooter : public Shooter
	{
	public:
		BulletShooter(Actor* owner, float cooldownTimer = 1.0f);
		virtual bool IsOnCooldown() const override;

	private:
		virtual void ShootImpl() override;
		Clock m_CooldownClock;
		float m_CooldownTime;

	protected:

	};
}

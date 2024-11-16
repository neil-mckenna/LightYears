#include "weapon/Shooter.h"

using namespace std;

namespace ly
{
	void Shooter::Shoot()
	{
		if (CanShoot() && !IsOnCooldown())
		{
			ShootImpl();
		}
	}

	Shooter::Shooter(Actor* owner)
		: m_Owner(owner)
	{


	}
}
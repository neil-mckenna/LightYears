#include "weapon/BulletShooter.h"
#include "weapon/Bullet.h"
#include "framework/Core.h"
#include "framework/World.h"


namespace ly
{
	BulletShooter::BulletShooter(Actor* owner, float cooldownTimer)
		:
		Shooter{ owner },
		m_CooldownClock{},
		m_CooldownTime{cooldownTimer}
	{

	}

	bool BulletShooter::IsOnCooldown() const
	{
		if (m_CooldownClock.getElapsedTime().asSeconds() > m_CooldownTime)
		{
			return false;
		}

		return true;
	}

	void BulletShooter::ShootImpl()
	{
		m_CooldownClock.restart();

		LOG("Shooting");

		weak<Bullet> newBullet =
			GetOwner()->GetWorld()->SpawnActor<Bullet>(
				GetOwner(),
				"SpaceShooterRedux/PNG/Lasers/laserBlue01.png"

				);

		/*LOG("Bullet Forward Vector Direction: x = %f, y = %f",
			newBullet.lock()->GetActorForwardDirection().x,
			newBullet.lock()->GetActorForwardDirection().y);*/

		// bullet spawn location with a slight offset in front off the ship
		newBullet.lock()->SetActorLocation(GetOwner()->GetActorLocation() + Vector2f(0.0f, -70.f));

		/*LOG("Bullet Rotation: rot = %f",
			newBullet.lock()->GetActorRotation());*/

		newBullet.lock()->SetActorRotation(GetOwner()->GetActorRotation());

	}


}
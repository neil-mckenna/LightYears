#include "weapon/Bullet.h"

namespace ly
{
	Bullet::Bullet(World* world, Actor* owner, const string& texturePath, float speed, float damage)
		: Actor{world, texturePath},
		m_Owner{owner},
		m_Speed{speed},
		m_Damage{damage}
	{

	}

	void Bullet::SetSpeed(float newSpeed)
	{
		m_Speed = newSpeed;
	}

	void Bullet::SetDamage(float newDamage)
	{
		m_Damage = newDamage;
	}

	void Bullet::Update(float dt)
	{
		Actor::Update(dt);

		Move(dt);

	}

	void Bullet::Move(float dt)
	{


		AddActorLocationOffset(GetActorForwardDirection() * m_Speed * dt);
	}
}
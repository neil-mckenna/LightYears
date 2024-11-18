#include "weapon/Bullet.h"

#include <cstdlib>
#include <ctime>

using namespace std;

namespace ly
{
	Bullet::Bullet(World* world, Actor* owner, const string& texturePath, float speed, float damage)
		: Actor{world, texturePath},
		m_Owner{owner},
		m_Speed{speed},
		m_Damage{damage}

	{
		m_ActorName = GenerateRandomName("Bullet");

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
		if (IsActorOutOfWindowBounds())
		{
			Destroy();
		}

	}

	void Bullet::BeginPlay()
	{
		Actor::BeginPlay();

		SetEnablePhysics(true);
	}

	void Bullet::Move(float dt)
	{


		AddActorLocationOffset(GetActorForwardDirection() * m_Speed * dt);
	}

	string Bullet::GenerateRandomName(const string& baseName) {

		// Seed the random number generator ONCE
		static bool seeded = false;
		if (!seeded) {
			std::srand(static_cast<unsigned>(std::time(nullptr)));
			seeded = true;
		}

		// Generate a random number with a wider range
		int randomNumber = std::rand() % 1000000; // Generates a number between 0 and 999999

		// Concatenate base name with the random number
		return baseName + "_" + std::to_string(randomNumber);
	}
}
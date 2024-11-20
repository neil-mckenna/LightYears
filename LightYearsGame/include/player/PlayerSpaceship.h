#pragma once

#include "spaceship/Spaceship.h"
#include "weapon/BulletShooter.h"


using namespace std;

namespace ly
{
	class BulletShooter;
	class PlayerSpaceShip : public SpaceShip
	{
	public:
		PlayerSpaceShip(World* owningWorld = nullptr, const string& texturePath = "");
		virtual void Update(float dt);

		float GetSpeed() const { return m_speed; }
		void SetSpeed(float newSpeed) { m_speed = newSpeed; }

		virtual void Shoot() override;

	private:
		void HandleInput();
		void NormalizeInput();
		void ClampInputOnEdge();
		void ConsumeInput(float dt);
		Vector2f m_MoveInput;
		float m_speed;

		unique<BulletShooter> m_Shooter;

	};
}
#include "player/PlayerSpaceship.h"
#include <SFML/System.hpp>
#include "framework/MathUtility.h"
#include "framework/Actor.h"
#include "weapon/BulletShooter.h"

using namespace std;
using namespace sf;

namespace ly
{
	PlayerSpaceship::PlayerSpaceship(World* owningWorld, const string& path)
		:
		SpaceShip{owningWorld, path},
		m_MoveInput{0.0f, 0.0f},
		m_speed{300.0f},
		m_Shooter{ new BulletShooter{this, 0.2f} }
	{
	}

	void PlayerSpaceship::Update(float dt)
	{
		SpaceShip::Update(dt);
		HandleInput();

		ConsumeInput(dt);
	}

	void PlayerSpaceship::Shoot()
	{
		if (m_Shooter)
		{
			m_Shooter->Shoot();
		}
	}

	void PlayerSpaceship::HandleInput()
	{
		// up and down
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			m_MoveInput.y = -1.f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			m_MoveInput.y = 1.f;
		}

		// left and right
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			m_MoveInput.x = -1.f;
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			m_MoveInput.x = 1.f;
		}

		ClampInputOnEdge();
		NormalizeInput();

		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			Shoot();
		}

	}

	void PlayerSpaceship::NormalizeInput()
	{
		Normalize(m_MoveInput);
		//LOG("move input is now %f, %f", m_MoveInput.x, m_MoveInput.y);
	}

	void PlayerSpaceship::ClampInputOnEdge()
	{
		Vector2f actorLocation = GetActorLocation();

		// just to get sprite size
		//LOG("Actor Size %f %f", GetActorSpriteSize().x, GetActorSpriteSize().y);

		if (actorLocation.x < 0 + (GetActorSpriteSize().x / 2)
			&& m_MoveInput.x == -1)
		{
			m_MoveInput.x = 0;
		}

		if (actorLocation.x > GetWindowSize().x - (GetActorSpriteSize().x / 2)
			&& m_MoveInput.x == 1.0f)
		{
			m_MoveInput.x = 0;
		}

		if (actorLocation.y < 0 + (GetActorSpriteSize().y / 2)
			&& m_MoveInput.y == -1)
		{
			m_MoveInput.y = 0;
		}

		if (actorLocation.y > GetWindowSize().y - (GetActorSpriteSize().y / 2)
			&& m_MoveInput.y == 1.0f)
		{
			m_MoveInput.y = 0;
		}

	}

	void PlayerSpaceship::ConsumeInput(float dt)
	{
		SetVelocity(m_MoveInput * m_speed);
		m_MoveInput.x = 0.f;
		m_MoveInput.y = 0.f;
	}

}


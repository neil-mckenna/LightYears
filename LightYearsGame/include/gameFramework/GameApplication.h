#pragma once

#include <framework/Application.h>
#include <framework/Actor.h>
#include <framework/Core.h>
#include "player/PlayerSpaceship.h"

namespace ly
{
	class Actor;
	class PlayerSpaceShip;
	class SpaceShip;

	class GameApplication : public Application
	{
	public:
		GameApplication();
		void Update(float dt) override;
	private:
		float counter;
		shared<PlayerSpaceShip> testPlayerSpaceship;
		shared<SpaceShip> testSpaceship_2;
	};

}

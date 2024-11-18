#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/AssetManager.h"
#include "player/PlayerSpaceship.h"
#include "config.h"

ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{


	GameApplication::GameApplication()
		: Application{800, 980, "LightYears", Style::Titlebar | Style::Close}
	{
		AssetManager::Get().SetAssetRootDirectory(GetResourceDir());

		LOG("GAME APPlication called");
		weak<World> newWorld = LoadWorld<World>();

		testPlayerSpaceship = newWorld.lock()->SpawnActor<PlayerSpaceship>();
		testPlayerSpaceship.lock()->SetActorLocation(Vector2f(400.f, 800.f));
		testPlayerSpaceship.lock()->SetVelocity(Vector2f(0.0f, -200.f));
		testPlayerSpaceship.lock()->SetActorRotation(0.0f);

		// sprite forward direction was not the same as the sprite
		testPlayerSpaceship.lock()->SetActorRotation(-90.0f);

		//testPlayerSpaceship.lock()->SetSpriteRotation(90.0f);

		/*LOG("Ship Rotation: rot = %f",
			testPlayerSpaceship.lock()->GetActorRotation());

		LOG("SpaceShip Forward vector Direction: x = %f, y = %f",
			testPlayerSpaceship.lock()->GetActorForwardDirection().x,
			testPlayerSpaceship.lock()->GetActorForwardDirection().y);*/


		//testPlayerSpaceship.lock()->SetActorRotation(0.0f);
		//testPlayerSpaceship.lock()->RescaleActor(1.0f, 1.0f);

		weak<SpaceShip> testSpaceShip =
			newWorld.lock()->SpawnActor<SpaceShip>();

		testSpaceShip.lock()->SetTexture("SpaceShooterRedux/PNG/playerShip1_blue.png");
		testSpaceShip.lock()->SetActorLocation(Vector2f(100.f, 50.f));

		counter = 0.f;

	}

	void GameApplication::Update(float dt)
	{
		counter += dt;

		//LOG("GAME APPlication updating counter: %f", counter);


		if (counter > 10.f)
		{
			if (!testPlayerSpaceship.expired())
			{
				testPlayerSpaceship.lock()->Destroy();
			}
		}
	}


}
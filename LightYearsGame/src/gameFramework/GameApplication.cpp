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
		shared<World> newWorld = LoadWorld<World>();

		testPlayerSpaceship = newWorld->SpawnActor<PlayerSpaceShip>();
		testPlayerSpaceship->SetTexture("SpaceShooterRedux/PNG/playerShip1_blue.png");

		testPlayerSpaceship->SetActorLocation(Vector2f(400.f, 800.f));
		testPlayerSpaceship->SetVelocity(Vector2f(0.0f, -200.f));
		testPlayerSpaceship->SetActorRotation(0.0f);

		// sprite forward direction was not the same as the sprite
		testPlayerSpaceship->SetActorRotation(-90.0f);

		testSpaceship_2 = newWorld->SpawnActor<SpaceShip>();
		testSpaceship_2->SetTexture("SpaceShooterRedux/PNG/playerShip1_blue.png");
		testSpaceship_2->SetActorLocation(Vector2f(100.f, 50.f));

		counter = 0.f;

	}

	void GameApplication::Update(float dt)
	{
		counter += dt;

		//LOG("GAME APPlication updating counter: %f", counter);


		/*if (counter > 10.f)
		{
			if (!testPlayerSpaceship.expired())
			{
				testPlayerSpaceship.lock()->Destroy();
			}
		}*/
	}


}
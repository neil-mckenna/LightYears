#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
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
		LOG("GAME APPlication called");
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		actorToDestroy = newWorld.lock()->SpawnActor<Actor>();

		actorToDestroy.lock()->SetTexture(GetResourceDir() + "SpaceShooterRedux/PNG/playerShip1_blue.png");
		actorToDestroy.lock()->SetActorLocation(Vector2f(400.f, 490.f));
		actorToDestroy.lock()->SetActorRotation(90.0f);
		actorToDestroy.lock()->RescaleActor(1.0f, 1.7f);

		counter = 0;

	}

	void GameApplication::Update(float dt)
	{
		counter += dt;

		//LOG("GAME APPlication updating counter: %f", counter);


		/*if (counter > 2.f)
		{
			if (!actorToDestroy.expired())
			{
				LOG("Destroy the actor");
				actorToDestroy.lock()->Destroy();
			}
		}*/
	}


}
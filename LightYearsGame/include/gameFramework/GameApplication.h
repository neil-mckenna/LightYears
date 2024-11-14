#pragma once

#include <framework/Application.h>
#include <framework/Actor.h>
#include <framework/Core.h>

namespace ly
{
	class Actor;
	class GameApplication : public Application
	{
	public:
		GameApplication();
		void Update(float dt) override;
	private:
		float counter;
		weak<Actor> actorToDestroy;
	};

}

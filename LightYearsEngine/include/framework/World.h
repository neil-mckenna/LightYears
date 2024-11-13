#pragma once

#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{
	class Application;
	class Actor;

	class World
	{
	public:
		World(Application* owningApp);

		void BeginPlayInternal();
		void UpdateInternal(float dt);

		virtual ~World();

		template<typename ActorType>
		weak<ActorType> SpawnActor();

	private:
		Application* m_owningApp;
		bool m_BeginPlay;

		void BeginPlay();
		void Update(float dt);

		List<shared<Actor>> m_Actors;
		List<shared<Actor>> m_pendingActors;

	};

	template<typename ActorType>
	weak<ActorType> World::SpawnActor()
	{
		shared<ActorType> newActor{ new ActorType{ this } };
		m_pendingActors.push_back(newActor);
		LOG("Actor Spawned");
		return weak<ActorType>();
	}


}
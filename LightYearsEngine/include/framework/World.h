#pragma once

#include "framework/Actor.h"
#include "framework/Core.h"
#include <SFML/Graphics.hpp>

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
		void Render(RenderWindow& window);

		// destructor
		virtual ~World();

		template<typename ActorType>
		shared<ActorType> SpawnActor();

	private:
		Application* m_owningApp;
		bool m_BeginPlay;

		void BeginPlay();
		void Update(float dt);

		List<shared<Actor>> m_Actors;
		List<shared<Actor>> m_pendingActors;

	};

	template<typename ActorType>
	shared<ActorType> World::SpawnActor()
	{
		// Create a new shared pointer of ActorType and initialize it with this world as the owner
		shared<ActorType> newActor = std::make_shared<ActorType>(this);

		// Add the new actor to the pending actors list
		m_pendingActors.push_back(newActor);

		LOG("Actor Spawned");

		// Return the shared pointer, allowing the caller to manage its lifetime directly
		return newActor;
	}



}
#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace ly
{
	World::World(Application* owningApp)
		: m_owningApp{ owningApp },
		m_BeginPlay{false},
		m_Actors{},
		m_pendingActors{}
	{
		LOG("World created");

	}

	void World::BeginPlayInternal()
	{

		if (!m_BeginPlay)
		{
			m_BeginPlay = true;
			BeginPlay();
		}

	}

	void World::UpdateInternal(float dt)
	{
		//LOG("Pending Actors size()  %d", m_pendingActors.size());
		for (shared<Actor> actor : m_pendingActors)
		{
			LOG("Pending Actor added to Actors");
			m_Actors.push_back(actor);

			actor->BeginPlayInternal();
		}

		m_pendingActors.clear();

		LOG("Actor size()  %d", m_Actors.size());
		for (shared<Actor> actor : m_Actors)
		{

			actor->Update(dt);
		}

		Update(dt);
	}


	void World::BeginPlay()
	{
		LOG("Begin Play");
	}

	void World::Update(float dt)
	{
		LOG("Updating at framerate %f", 1.f / dt);
	}

	World::~World()
	{
	}
}
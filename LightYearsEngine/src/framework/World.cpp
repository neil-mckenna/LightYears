#include "framework/World.h"
#include "framework/Core.h"

namespace ly
{
	World::World(Application* owningApp) : m_owningApp{ owningApp }, m_BeginPlay{false}
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
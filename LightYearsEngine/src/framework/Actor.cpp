#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{
	Actor::Actor(World* owningWorld)
		: m_owningWorld(owningWorld),
		m_hasBeganPlay(false)
	{


	}
	void Actor::BeginPlayInternal()
	{
		if (!m_hasBeganPlay)
		{
			m_hasBeganPlay = true;
			BeginPlay();
		}

	}

	void Actor::BeginPlay()
	{
		LOG("Actor begin play");

	}

	void Actor::Update(float dt)
	{
		//LOG("Actor updating");

	}
	Actor::~Actor()
	{
		LOG("Ahhhhhh!!!! ------------ Actor Destroyed");
	}
}


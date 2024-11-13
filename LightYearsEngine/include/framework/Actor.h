#pragma once

namespace ly
{
	class World;

	class Actor
	{
	public:
		Actor(World* owningWorld);

		void BeginPlayInternal();
		virtual void BeginPlay();

		virtual void Update(float dt);

		virtual ~Actor();



	private:
		World* m_owningWorld;
		bool m_hasBeganPlay;

	};




}
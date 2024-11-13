#pragma once
#include <SFML/Graphics.hpp>
#include <Box2d/box2d.h>
#include "framework/Core.h"

using namespace sf;

namespace ly
{

	class World;
	class Application
	{
	public:
		Application();
		void Run();

		template<typename WorldType>
		weak<WorldType> LoadWorld();


	private:
		RenderWindow m_Window;
		float m_TargetFrameRate;
		Clock m_TickClock;
		shared<World> m_currentWorld;

		void UpdateInternal(float dt);
		virtual void Update(float dt);
		void RenderInternal();
		virtual void Render();



	};

	template<typename WorldType>
	std::weak_ptr<WorldType> Application::LoadWorld()
	{
		LOG("Attempting to load world of type WorldType");

		shared<WorldType> newWorld{ new WorldType{this} };
		LOG("WorldType instance created");

		m_currentWorld = newWorld;
		LOG("m_currentWorld set");

		// call play after creation
		m_currentWorld->BeginPlayInternal();

		return newWorld;
	}



}
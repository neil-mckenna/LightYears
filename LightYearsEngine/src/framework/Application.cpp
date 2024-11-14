#include <iostream>
#include "framework/Application.h"

#include "framework/Core.h"
#include "framework/World.h"


using namespace sf;
using namespace std;

const int GAMEWIDTH = 768;
const int GAMEHEIGHT = 1024;

namespace ly
{

	Application::Application(unsigned int windowWidth, unsigned int windowHeight,
		const std::string& title, sf::Uint32 style

	) :
		m_Window{ sf::VideoMode(windowWidth, windowHeight),  title, style },
		m_TargetFrameRate{ 60.f },
		m_TickClock{},
		m_currentWorld{ nullptr }
	{

	}

	void Application::Run()
	{
		m_TickClock.restart();
		float accumlatedTime = 0.f;
		float targetDeltaTime = 1.f / m_TargetFrameRate;

		while (m_Window.isOpen())
		{
			Event windowEvent;
			while (m_Window.pollEvent(windowEvent))
			{
				// close the window
				if (windowEvent.type == Event::EventType::Closed)
				{
					m_Window.close();
				}
			}
			float frameDeltaTime = m_TickClock.restart().asSeconds();
			accumlatedTime += frameDeltaTime;
			while (accumlatedTime > targetDeltaTime)
			{
				accumlatedTime -= targetDeltaTime;
				UpdateInternal(targetDeltaTime);
				RenderInternal();
			}

			//LOG("Updating frame rate at %f", 1.f /frameDeltaTime);
		}


	}

	void Application::RenderInternal()
	{
		m_Window.clear();

		Render();

		m_Window.display();
	}

	void Application::UpdateInternal(float dt)
	{

		Update(dt);

		if (m_currentWorld)
		{
			m_currentWorld->BeginPlayInternal();
			m_currentWorld->UpdateInternal(dt);
		}
		else
		{
			LOG("No current world");
		}

	}

	void Application::Render()
	{
		RectangleShape rect{ Vector2f{100,100} };
		rect.setOrigin(50.0f, 50.0f);
		rect.setFillColor(Color::Green);
		rect.setPosition(GAMEWIDTH / 2, GAMEHEIGHT - 70.0f);


		m_Window.draw(rect);

	}

	void Application::Update(float dt)
	{

	}
}


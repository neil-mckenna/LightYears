#include <iostream>
#include "framework/Application.h"

using namespace sf;
using namespace std;

const int GAMEWIDTH = 768;
const int GAMEHEIGHT = 1024;

namespace ly
{

	// Application constructor with default settings
	Application::Application() :
		m_Window{ VideoMode(GAMEWIDTH, GAMEHEIGHT), "LightYearsGame" },
		m_TargetFrameRate{60.0f},
		m_TickClock{}
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
				Update(targetDeltaTime);
				Render();
			}
			//cout << "Updating at framerate: " << 1.f /frameDeltaTime << endl;
		}
	}

	void Application::Update(float dt)
	{

	}

	void Application::Render()
	{
		m_Window.clear();

		RectangleShape rect{ Vector2f{100,100} };
		rect.setOrigin(50.0f, 50.0f);
		rect.setFillColor(Color::Green);
		rect.setPosition(GAMEWIDTH / 2, GAMEHEIGHT - 70.0f);


		m_Window.draw(rect);

		m_Window.display();
	}

}


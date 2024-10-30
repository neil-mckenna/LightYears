#include "framework/Application.h"

using namespace sf;

namespace ly
{


	Application::Application() : m_Window{VideoMode(768, 1024), "LightYearsGame"}
	{

	}

	void Application::Run()
	{
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
		}
	}

}


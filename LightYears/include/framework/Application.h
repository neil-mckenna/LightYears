#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace ly
{
	class Application
	{
	public:
		Application();
		void Run();

	private:
		RenderWindow m_Window;


	};


}
#pragma once
#include <SFML/Graphics.hpp>
#include <Box2d/box2d.h>

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
		float m_TargetFrameRate;
		Clock m_TickClock;

		void UpdateInternal(float dt);
		virtual void Update(float dt);
		void RenderInternal();
		virtual void Render();

	};


}
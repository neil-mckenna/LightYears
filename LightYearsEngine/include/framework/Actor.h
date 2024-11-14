#pragma once

#include "framework/Object.h"
#include "framework/Core.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace ly
{
	class World;

	class Actor : public Object
	{
	public:
		Actor(World* owningWorld, const string &texturePath = "");

		virtual void BeginPlay();
		void BeginPlayInternal();

		virtual void Update(float dt);
		void UpdateInternal(float dt);

		void SetTexture(const string texturePath);

		void Render(RenderWindow &window);

		// destructor
		virtual ~Actor();

	private:
		World* m_owningWorld;
		bool m_hasBeganPlay;

		Sprite m_Sprite;
		Texture m_Texture;
	};




}
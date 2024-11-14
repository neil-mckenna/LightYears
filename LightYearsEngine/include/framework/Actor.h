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

		void SetActorLocation(const Vector2f& newLocation);
		void SetActorRotation(float newRot);

		Vector2f GetActorLocation() const;
		float GetActorRotation() const;

		void AddActorLocationOffset(const Vector2f& offsetAmt);
		void AddActorLocationOffset(float rotOffsetAmt);

		Vector2f GetActorForwardDirection() const;
		Vector2f GetActorRightDirection() const;

		void RescaleActor(float scaleXAmt, float scaleYAmt);

		// destructor
		virtual ~Actor();

	private:
		World* m_owningWorld;
		bool m_hasBeganPlay;

		Sprite m_Sprite;
		shared<Texture> m_Texture;

		void CenterPivot();
	};




}
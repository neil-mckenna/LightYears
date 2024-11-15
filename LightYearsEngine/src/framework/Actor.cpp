#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"
#include "framework/MathUtility.h"
#include "framework/World.h"

namespace ly
{
	Actor::Actor(World* owningWorld, const string& texturePath) :
		m_owningWorld(owningWorld),
		m_hasBeganPlay(false),
		m_Sprite{},
		m_Texture{}

	{
		SetTexture(texturePath);

	}

	void Actor::SetTexture(const string texturePath)
	{
		// call singleton
		m_Texture = AssetManager::Get().LoadTexture(texturePath);

		if (!m_Texture)
		{
			return;
		}

		m_Sprite.setTexture(*m_Texture);

		int textureWidth = m_Texture->getSize().x;
		int textureHeight = m_Texture->getSize().y;

		m_Sprite.setTextureRect(IntRect(Vector2i{ 0,0 }, Vector2i{ textureWidth, textureHeight }));

		// center origin
		CenterPivot();
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

	void Actor::UpdateInternal(float dt)
	{
		if (!IsPendingDestroy())
		{
			Update(dt);
		}
	}

	void Actor::Render(RenderWindow& window)
	{
		window.draw(m_Sprite);
	}

	void Actor::SetActorLocation(const Vector2f& newLocation)
	{
		m_Sprite.setPosition(newLocation);
	}

	void Actor::SetActorRotation(const float newRot)
	{
		m_Sprite.setRotation(newRot);
	}

	Vector2f Actor::GetActorLocation() const
	{
		return m_Sprite.getPosition();
	}

	float Actor::GetActorRotation() const
	{
		return m_Sprite.getRotation();
	}

	void Actor::AddActorLocationOffset(const Vector2f& offsetAmt)
	{
		SetActorLocation(GetActorLocation() + offsetAmt);
	}

	void Actor::AddActorLocationOffset(float rotOffsetAmt)
	{
		SetActorRotation(GetActorRotation() + rotOffsetAmt);
	}

	Vector2f Actor::GetActorForwardDirection() const
	{
		return RotationToVector(GetActorRotation());
	}

	Vector2f Actor::GetActorRightDirection() const
	{
		// from the actor ^ to >
		return RotationToVector(GetActorRotation() + 90);
	}

	void Actor::RescaleActor(float scaleXAmt, float scaleYAmt)
	{
		m_Sprite.setScale(scaleXAmt, scaleYAmt);
	}

	Vector2u Actor::GetWindowSize() const
	{
		return m_owningWorld->GetWindowSize();
	}

	Vector2f Actor::GetActorSpriteSize() const
	{
		float width = m_Sprite.getGlobalBounds().width;
		float height = m_Sprite.getGlobalBounds().height;

		return Vector2f(width, height);
	}

	void Actor::CenterPivot()
	{
		FloatRect bounds = m_Sprite.getGlobalBounds();
		m_Sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);

	}

	Actor::~Actor()
	{
		LOG("Ahhhhhh!!!! ------------ Actor Destroyed");
	}
}


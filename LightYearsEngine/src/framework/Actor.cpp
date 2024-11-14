#include "framework/Actor.h"
#include "framework/Core.h"

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
		m_Texture.loadFromFile(texturePath);
		m_Sprite.setTexture(m_Texture);

		int textureWidth = m_Texture.getSize().x;
		int textureHeight = m_Texture.getSize().y;

		m_Sprite.setTextureRect(IntRect(Vector2i{ 0,0 }, Vector2i{ textureWidth, textureHeight }));
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


	Actor::~Actor()
	{
		LOG("Ahhhhhh!!!! ------------ Actor Destroyed");
	}
}


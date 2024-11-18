#pragma

#include "framework/Actor.h"

using namespace std;

namespace ly
{
	class Bullet : public Actor
	{
	public:
		Bullet(
			World* world,
			Actor* owner,
			const string& texturePath,
			float speed = 500.0f,
			float damage = 10.0f
			);

		void SetSpeed(float newSpeed);
		void SetDamage(float newDamage);

		virtual void Update(float dt) override;
		virtual void BeginPlay() override;
	private:
		Actor* m_Owner;
		float m_Speed;
		float m_Damage;

		void Move(float dt);

		string GenerateRandomName(const string& baseName);

	};

}
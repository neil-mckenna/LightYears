#pragma once

namespace ly
{
	class Actor;
	class Shooter
	{
	public:
		void Shoot();

		virtual bool CanShoot() const { return true; }
		virtual bool IsOnCooldown() const { return false; }
		Actor* GetOwner() const { return m_Owner; }

	private:
		virtual void ShootImpl() = 0;
		Actor* m_Owner;

	protected:
		Shooter(Actor* owner);

	};

}
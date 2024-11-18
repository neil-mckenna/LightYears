#pragma once

namespace ly
{
	class Object
	{
	public:
		Object();

		virtual void Destroy();
		bool IsPendingDestroy() const { return m_isPendingDestroy; }


		virtual ~Object();
	private:
		bool m_isPendingDestroy;
	};

}
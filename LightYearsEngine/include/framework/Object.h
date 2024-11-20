#pragma once
#include <memory>
#include <iostream>
#include "framework/Core.h"

using namespace std;

namespace ly
{
	class Object : enable_shared_from_this<Object>
	{
	public:
		Object();

		virtual void Destroy();
		bool IsPendingDestroy() const { return m_isPendingDestroy; }

		weak<Object> GetWeakRef();
		weak<const Object> GetWeakRef() const;

		shared<const Object> GetSharedRef() const;

		Object* GetRawPtr();


		virtual ~Object();
	private:
		bool m_isPendingDestroy;
	};

}
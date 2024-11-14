#include "framework/Object.h"
#include "framework/Core.h"

namespace ly
{
	Object::Object() : m_isPendingDestroy{false}
	{


	}

	void Object::Destroy()
	{
		m_isPendingDestroy = true;
	}


	Object::~Object()
	{
		LOG("Object destroyed");
	}

}



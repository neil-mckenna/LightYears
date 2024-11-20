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

	weak<Object> Object::GetWeakRef()
	{
		return weak_from_this();
	}

	weak<const Object> Object::GetWeakRef() const
	{
		return weak<const Object>();
	}


	Object* Object::GetRawPtr()
	{
		return this;
	}



	Object::~Object()
	{
		LOG("Object destroyed");
	}

}



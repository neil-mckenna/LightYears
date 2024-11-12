#include "gameFramework/GameApplication.h"

ly::GameApplication* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{


	GameApplication::GameApplication()
	{
	}

}
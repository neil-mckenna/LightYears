#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "framework/Application.h"

using namespace	std;
using namespace sf;
using namespace ly;

int main()
{

	unique_ptr<ly::Application> app = make_unique<ly::Application>();
	app->Run();

}

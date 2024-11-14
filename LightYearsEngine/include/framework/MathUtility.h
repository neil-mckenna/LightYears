#pragma once

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

namespace ly
{
	Vector2f RotationToVector(float rotation);
	float DegreesToRadians(float degrees);
	float RadiansToDegrees(float radians);
}
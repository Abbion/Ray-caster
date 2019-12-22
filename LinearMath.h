#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

struct LinearFunction
{
	float a, b;
};


LinearFunction CreateLinearFunction(const sf::Vector2f v_F1, const sf::Vector2f v_F2);
LinearFunction CreatePerpendicularLinearFunction(const LinearFunction v_Function, const sf::Vector2f v_F1);
sf::Vector2f GetIntersectionOfLinearFunctions(const LinearFunction v_Func1, const LinearFunction v_Func2);
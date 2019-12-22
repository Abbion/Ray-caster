#pragma once
#include "CircleWall.h"
#include "RectangleWall.h"

const int CircleCount = 5;
const int RectangleCount = 5;

CircleInfo CircleSetUp[CircleCount] = {
	sf::Vector2f(0.5, 0.5), 100,
	sf::Vector2f(0.2, 0.16), 90,
	sf::Vector2f(0.8, 0.8), 60,
	sf::Vector2f(0.9, 0.3), 40,
	sf::Vector2f(0.8, 0.8), 90,
};

RectangleInfo RectangleSetUp[RectangleCount] = {
	sf::Vector2f(0.1, 0.7), sf::Vector2f(0.093, 0.16),
	sf::Vector2f(0.7, 0.4), sf::Vector2f(0.0625, 0.22),
	sf::Vector2f(0.4, 0.75), sf::Vector2f(0.0875, 0.177),
	sf::Vector2f(0.5, 0.2), sf::Vector2f(0.1125, 0.133),
	sf::Vector2f(0.02, 0.02), sf::Vector2f(0.96875, 0.944)
};
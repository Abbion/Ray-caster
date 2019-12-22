#pragma once
#include <SFML/Graphics.hpp>
#include "CircleWall.h"
#include "RectangleWall.h"


class Map : public sf::Drawable
{
public:
	Map(CircleInfo* v_circles, int v_circleCount, RectangleInfo* v_rectangles, int v_rectangleCount);
	~Map();

	CircleWall m_CircleWalls;
	RectangleWall m_RectangleWalls;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#include "Map.h"

Map::Map(CircleInfo* v_circles, int v_circleCount, RectangleInfo* v_rectangles, int v_rectangleCount) :
    m_CircleWalls(v_circles, v_circleCount), m_RectangleWalls(v_rectangles, v_rectangleCount)
{

}

Map::~Map()
{

}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_CircleWalls, states);
    target.draw(m_RectangleWalls, states);
}
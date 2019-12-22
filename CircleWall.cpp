#include "CircleWall.h"
#include <math.h>
#include <limits>
#include <iostream>

extern const int WindowWidth;
extern const int WindowHeight;

CircleWall::CircleWall(CircleInfo* v_circles, int v_count)
{
	for (int i = 0; i < v_count; i++)
	{
		sf::CircleShape NewCircle(v_circles[i].Radius);
		NewCircle.setPosition(sf::Vector2f(v_circles[i].Position.x * WindowWidth, v_circles[i].Position.y * WindowHeight));
		NewCircle.setOrigin(sf::Vector2f(v_circles[i].Radius, v_circles[i].Radius));
		NewCircle.setFillColor(sf::Color::Transparent);
		NewCircle.setOutlineColor(sf::Color(242, 65, 80));
		NewCircle.setOutlineThickness(1);
		m_CircleArray.push_back(NewCircle);
	}
}

CircleWall::~CircleWall()
{}

float CircleWall::GetMinimalDistance(const sf::Vector2f& v_point)
{
	float MinimalDistance = std::numeric_limits<float>::max();
	for (int i = 0; i < m_CircleArray.size(); i++)
	{
		float XVector = v_point.x - m_CircleArray.at(i).getPosition().x;
		float YVector = v_point.y - m_CircleArray.at(i).getPosition().y;
		float LocalMin = std::abs(std::sqrt((XVector * XVector) + (YVector * YVector)) - m_CircleArray.at(i).getRadius());
		MinimalDistance = std::min(LocalMin, MinimalDistance);
	}
	return MinimalDistance;
}


void CircleWall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < m_CircleArray.size(); i++)
	{
		target.draw(m_CircleArray.at(i));
	}
}
#include "RectangleWall.h"
#include <limits>

extern const int WindowWidth;
extern const int WindowHeight;

RectangleWall::RectangleWall(RectangleInfo* v_rectangles, int v_count)
{
    for (int i = 0; i < v_count; i++)
	{
		sf::RectangleShape NewRectangle(sf::Vector2f(v_rectangles[i].Size.x * WindowWidth, v_rectangles[i].Size.y * WindowHeight));
		NewRectangle.setPosition(sf::Vector2f(v_rectangles[i].Position.x * WindowWidth, v_rectangles[i].Position.y * WindowHeight));
		NewRectangle.setFillColor(sf::Color::Transparent);
		NewRectangle.setOutlineColor(sf::Color(56, 199, 189));
		NewRectangle.setOutlineThickness(1);
		m_RectangleArray.push_back(NewRectangle);
	}
}

RectangleWall::~RectangleWall()
{}

float RectangleWall::GetMinimalDistance(const sf::Vector2f& v_point)
{
	float distance = std::numeric_limits<float>::max();
    for (int i = 0; i < m_RectangleArray.size(); i++)
	{
		sf::Vector2f Vect1(m_RectangleArray.at(i).getPosition());
		sf::Vector2f Vect2(sf::Vector2f(m_RectangleArray.at(i).getPosition().x + m_RectangleArray.at(i).getSize().x, m_RectangleArray.at(i).getPosition().y));
		sf::Vector2f Vect3(sf::Vector2f(m_RectangleArray.at(i).getPosition().x + m_RectangleArray.at(i).getSize().x, m_RectangleArray.at(i).getPosition().y + m_RectangleArray.at(i).getSize().y));
		sf::Vector2f Vect4(sf::Vector2f(m_RectangleArray.at(i).getPosition().x, m_RectangleArray.at(i).getPosition().y  + m_RectangleArray.at(i).getSize().y));
		
		distance = std::min(GetMinimalDistanceFromLine(Vect1, Vect2, v_point), distance);
		distance = std::min(GetMinimalDistanceFromLine(Vect2, Vect3, v_point), distance);
		distance = std::min(GetMinimalDistanceFromLine(Vect3, Vect4, v_point), distance);
		distance = std::min(GetMinimalDistanceFromLine(Vect4, Vect1, v_point), distance);
	}
	return distance;
}

void RectangleWall::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < m_RectangleArray.size(); i++)
	{
		target.draw(m_RectangleArray.at(i));
	}
}

float RectangleWall::GetMinimalDistanceFromLine(const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& v_point)
{
	float dx = p2.x - p1.x;
	float dy = p2.y - p1.y;

	float distance = ((v_point.x - p1.x) * dx + (v_point.y - p1.y) * dy) / (dx * dx + dy * dy);

	if (distance < 0)
	{
		dx = v_point.x - p1.x;
		dy = v_point.y - p1.y;
	}
	else if (distance > 1)
	{
		return std::numeric_limits<float>::max();
	}
	else
	{
		sf::Vector2f ToughtPoint(p1.x + distance * dx, p1.y + distance * dy);
		dx = v_point.x - ToughtPoint.x;
		dy = v_point.y - ToughtPoint.y;
	}

	return std::sqrt(dx * dx + dy * dy);
}
#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

typedef std::vector<sf::CircleShape> CircleVector;

struct CircleInfo
{
	sf::Vector2f Position;
	float Radius;
};

class CircleWall : public sf::Drawable
{
public:
	CircleWall(CircleInfo* v_circles, int v_count);
	~CircleWall();

	float GetMinimalDistance(const sf::Vector2f& v_point);
	
private:
	CircleVector m_CircleArray;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
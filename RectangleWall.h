#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

typedef std::vector<sf::RectangleShape> RectangleVector;

struct RectangleInfo
{
	sf::Vector2f Position;
	sf::Vector2f Size;
};

class RectangleWall : public sf::Drawable
{
public:
    RectangleWall(RectangleInfo* v_rectangles, int v_count);
    ~RectangleWall();

    float GetMinimalDistance(const sf::Vector2f& v_point);

private:
    RectangleVector m_RectangleArray;

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	float GetMinimalDistanceFromLine(const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& v_point);
};
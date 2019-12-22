#include "VectorMath.h"
#include <math.h>

sf::Vector2f AddVectors(const sf::Vector2f v_vec1, const sf::Vector2f v_vec2)
{
	return sf::Vector2f(v_vec1.x + v_vec2.x, v_vec1.y + v_vec2.y);
}

sf::Vector2f SubVectors(const sf::Vector2f v_vec1, const sf::Vector2f v_vec2)
{
	return sf::Vector2f(v_vec1.x - v_vec2.x, v_vec1.y - v_vec2.y);
}

sf::Vector2f ScaleVector(const sf::Vector2f v_vec1, const float scalar)
{
	return sf::Vector2f(v_vec1.x * scalar, v_vec1.y * scalar);
}

float GetVectorLength(const sf::Vector2f v_vec1)
{
	return std::sqrt((v_vec1.x * v_vec1.x) + (v_vec1.y * v_vec1.y));
}

sf::Vector2f GetUnitVector(const sf::Vector2f v_vec1)
{
	float Divider = GetVectorLength(v_vec1);
	return sf::Vector2f(v_vec1.x / Divider, v_vec1.y / Divider);
}

float DotProduct(const sf::Vector2f v_vec1, const sf::Vector2f v_vec2)
{
	return v_vec1.x * v_vec2.x + (v_vec1.y * v_vec2.y);
}

float AngleBetweenVectors(const sf::Vector2f v_vec1, const sf::Vector2f v_vec2)
{
	return DotProduct(v_vec1, v_vec2) / (GetVectorLength(v_vec1) * GetVectorLength(v_vec2));
}

sf::Vector2f getVectorProjection(const sf::Vector2f v_vec1, const sf::Vector2f v_vec2)
{
	return ScaleVector(v_vec2, (DotProduct(v_vec1, v_vec2) / DotProduct(v_vec2, v_vec2))); 
}

float getVectorProjectionLength(const sf::Vector2f v_vec1, const sf::Vector2f v_vec2)
{
	return GetVectorLength(getVectorProjection(v_vec1, v_vec2));
}
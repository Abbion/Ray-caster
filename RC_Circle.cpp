#include "RayCasting.h"
#include <math.h>

extern const int WindowWidth;
extern const int WindowHeight;

float DistanceCircle(const CircleInfo& v_CircleInfo, const sf::Vector2i& v_MousePos)
{
	float XVector = v_MousePos.x - v_CircleInfo.Position.x * WindowWidth;
	float YVector = v_MousePos.y - v_CircleInfo.Position.y * WindowHeight;
	return std::abs(std::sqrt((XVector * XVector) + (YVector * YVector)) - v_CircleInfo.Radius);
}
#pragma once
#include "Player.h"
#include "Map.h"
#include <vector>

class RayCaster
{
public:
	const float m_MaxRayLength = 2000.0f;

public:
	RayCaster(Map& v_map);
	~RayCaster();

	void StartCastingForPlayer(const Player& v_player);
	const std::vector<sf::Vector2f> getIntersectionsWithWalls() const;
	const std::vector<float> getRayLengths() const;

private:
	Map *p_Map;

	std::vector<sf::Vector2f> m_IntersectionsWithWalls;
	std::vector<float> m_RayLengths;

private:
	void CastRays(const Player& v_player);
	void CreateProperRayLengths(const Player& v_player);
};

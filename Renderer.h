#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "RayCaster.h"

#include "Player.h"

class Renderer : public sf::Drawable
{
public:
	Renderer(std::vector<float>& v_RayLengths, float v_MaxRayLength, const Player& v_Player);
	~Renderer();

private:
	std::vector<sf::RectangleShape> m_Samples;
	float m_MinWallSize = 20.0f;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	float GetGrayScaleColor(const float& v_RayLength, const float& v_MaxRayLength);
	void CreateRenderLine(const float& v_RayLength, const float& v_GrayScaleColor, int WallNumber);
};

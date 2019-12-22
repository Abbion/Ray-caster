#include "Renderer.h"
#include "LinearMath.h"
#include "VectorMath.h"
#include <math.h>

extern const int WindowWidth;
extern const int WindowHeight;
extern const int SampleCount;

Renderer::Renderer(std::vector<float>& v_RayLengths, float v_MaxRayLength, const Player& v_Player)
{
	for (int i = 0; i < v_RayLengths.size(); i++)
	{
		float Length = v_RayLengths.at(i);
		float Color = GetGrayScaleColor(Length, v_MaxRayLength);
		CreateRenderLine(Length, Color, i);
	}
}

Renderer ::~Renderer()
{

}

void Renderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < m_Samples.size(); i++)
	{
		target.draw(m_Samples.at(i));
	}
}

float Renderer::GetGrayScaleColor(const float& v_RayLength, const float& v_MaxRayLength)
{
	float GrayScaleColor = 255 - (255 * (v_RayLength / (v_MaxRayLength * 0.7f)));
	if(GrayScaleColor < 0)
		GrayScaleColor = 0;
	return GrayScaleColor;
}

void Renderer::CreateRenderLine(const float& v_RayLength, const float& v_GrayScaleColor, int WallNumber)
{
	float WallHeight = WindowHeight * (1.0f / ((v_RayLength * (1.0f/100.0f)) + 0.25f));
	if (WallHeight < m_MinWallSize)
		WallHeight = m_MinWallSize;

	sf::RectangleShape RenderLine;
	float RectPosX = WindowWidth * (WallNumber / (float)SampleCount);
	RenderLine.setPosition(sf::Vector2f(RectPosX, WindowHeight / 2));
	RenderLine.setSize(sf::Vector2f(WindowWidth / (float)SampleCount, WallHeight));
	RenderLine.setOrigin(0, RenderLine.getSize().y / 2);
	RenderLine.setFillColor(sf::Color(v_GrayScaleColor, v_GrayScaleColor, v_GrayScaleColor));
	m_Samples.push_back(RenderLine);	
}
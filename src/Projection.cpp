#include "Projection.h"
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
		//float GrayScaleColor = 255 - (255 * (Length / v_MaxRayLength));
		float GrayScaleColor = (255 * (1/ (Length * 1.0f/v_MaxRayLength + 1.0f)));
		if(GrayScaleColor < 0)
			GrayScaleColor = 0;

		float WallHeight = WindowHeight * (1 - (Length / v_MaxRayLength));
		//float WallHeight = WindowHeight * (1 / ((Length * (1.0f/100.0f)) + 0.09f));
		if (WallHeight < m_MinWallSize)
			WallHeight = m_MinWallSize;

		sf::RectangleShape RenderLine;
		float RectPosX = WindowWidth * (i / (float)SampleCount);
		RenderLine.setPosition(sf::Vector2f(RectPosX, WindowHeight / 2));
		RenderLine.setSize(sf::Vector2f(WindowWidth / (float)SampleCount, WallHeight));
		RenderLine.setOrigin(0, RenderLine.getSize().y / 2);
		RenderLine.setFillColor(sf::Color(GrayScaleColor, GrayScaleColor, GrayScaleColor));
		m_Samples.push_back(RenderLine);
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

void Renderer::NormalizeView(std::vector<float>& v_RayLengths)
{
	double RaySum = 0;
	for(int i = 0; i < v_RayLengths.size(); i++)
		RaySum += v_RayLengths.at(i);

	for(int i = 0; i < m_Samples.size(); i++)
	{
		float WallWidth = v_RayLengths.at(i) / RaySum;
		m_Samples.at(i).setSize(sf::Vector2f(WallWidth * WindowWidth, m_Samples.at(i).getSize().y));

		if(i == 0)
			m_Samples.at(i).setPosition(sf::Vector2f(0, m_Samples.at(i).getPosition().y));

		else
		{
			float WallPosX = m_Samples.at(i - 1).getPosition().x + m_Samples.at(i - 1).getSize().x;
			m_Samples.at(i).setPosition(sf::Vector2f(WallPosX, m_Samples.at(i).getPosition().y));
		}
	}
}
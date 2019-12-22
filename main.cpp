#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "VectorMath.h"
#include "Trigonometri.h"
#include "LinearMath.h"

#include "MapData.h"
#include "Player.h"
#include "Map.h"
#include "RayCaster.h"
#include "Renderer.h"
#include "Mouse.h"

extern const int WindowWidth = 1600;
extern const int WindowHeight = 900;
extern const int SampleCount = 1600;

sf::Vector2i MousePos;

sf::Clock Clock;
float DeltaTime;

enum DrawingLayer
{
	TopDown = 1,
	Render = 2,
};
int DrawLayer = DrawingLayer::TopDown;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "Ray casting");
	window.setMouseCursorVisible(false);

	GameMouse mouse(window);

	Player player1(sf::Vector2f(50, WindowHeight / 2), 20);
	Map Level(CircleSetUp, CircleCount, RectangleSetUp, RectangleCount);
	RayCaster ray(Level);

	int RayTest = 0;

	while (window.isOpen())
	{
		DeltaTime = Clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::F1)
				{
					if (DrawLayer == DrawingLayer::TopDown)
						DrawLayer = DrawingLayer::Render;
					else if (DrawLayer == DrawingLayer::Render)
						DrawLayer = DrawingLayer::TopDown | DrawingLayer::Render;
					else
						DrawLayer = DrawingLayer::TopDown;

				}

				if (event.key.code == sf::Keyboard::F2)
				{
					player1.m_Pov += 10;
					if (player1.m_Pov > 360)
						player1.m_Pov = 360;
				}

				if (event.key.code == sf::Keyboard::F3)
				{
					player1.m_Pov -= 10;
					if (player1.m_Pov < 0)
						player1.m_Pov = 0;
				}

				if (event.key.code == sf::Keyboard::Num1)
				{
					RayTest -= 10;
					if (RayTest < 0)
						RayTest = 0;
				}

				if (event.key.code == sf::Keyboard::Num2)
				{
					RayTest += 10;
					if (RayTest > SampleCount)
						RayTest = SampleCount;
				}

				if (event.key.code == sf::Keyboard::Tab)
					std::cout << "Stop\n";

				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
		}

		ray.StartCastingForPlayer(player1);

		mouse.update();

		player1.DeltaMouse = mouse.getMouseDelta();

		player1.update(DeltaTime);
		auto RayLengths = ray.getRayLengths();
		auto Intersections = ray.getIntersectionsWithWalls();
		Renderer worldRender(RayLengths, ray.m_MaxRayLength, player1);

		//Vector test
		sf::VertexArray PlayerRayToWall(sf::Lines, 2);
		PlayerRayToWall[0].position = player1.PlayerObject.getPosition();
		PlayerRayToWall[1].position = Intersections.at(RayTest);

		PlayerRayToWall[0].color = sf::Color::Blue;
		PlayerRayToWall[1].color = sf::Color::Blue;

		sf::VertexArray ShadowRay(sf::Lines, 2);
		ShadowRay[0].position = player1.PlayerObject.getPosition();
		ShadowRay[1].position = AddVectors(ShadowRay[0].position, getVectorProjection(SubVectors(Intersections.at(RayTest), ShadowRay[0].position), player1.getLookAt()));

		ShadowRay[0].color = sf::Color::Magenta;
		ShadowRay[1].color = sf::Color::Magenta;

		window.clear(sf::Color(59, 59, 59));
		if(DrawLayer & DrawingLayer::Render)
			window.draw(worldRender);
		if (DrawLayer & DrawingLayer::TopDown)
		{
			window.draw(Level);
			window.draw(player1);
			window.draw(PlayerRayToWall);
			window.draw(ShadowRay);
		}

		window.display();
	}

	return 0;
}
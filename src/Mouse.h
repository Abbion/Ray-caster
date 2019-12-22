#pragma once
#include <SFML/Graphics.hpp>

class GameMouse
{
public:
	GameMouse(sf::Window& v_window);
	~GameMouse();
	
	void update();

	sf::Vector2i getMouseDelta() { return m_DeltaMousePos; }
private:
	sf::Window* p_MainWindow = nullptr;
	sf::Vector2i m_LastMousePos;
	sf::Vector2i m_DeltaMousePos;
};
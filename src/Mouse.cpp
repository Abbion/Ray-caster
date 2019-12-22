#include "Mouse.h"

GameMouse::GameMouse(sf::Window& v_window) :
    p_MainWindow(&v_window), m_LastMousePos(0, 0)
{

}

GameMouse::~GameMouse()
{

}

void GameMouse::update()
{
    m_LastMousePos = sf::Mouse::getPosition(*p_MainWindow);
    sf::Mouse::setPosition(sf::Vector2i(p_MainWindow->getPosition().x + p_MainWindow->getSize().x / 2, p_MainWindow->getPosition().y + p_MainWindow->getSize().y / 2));
    m_DeltaMousePos = sf::Vector2i(m_LastMousePos.x - sf::Mouse::getPosition(*p_MainWindow).x, m_LastMousePos.y - sf::Mouse::getPosition(*p_MainWindow).y);
}
#include "Player.h"
#include <iostream>
#include <math.h>

extern const int WindowWidth;
extern const int WindowHeight;

Player::Player(sf::Vector2f v_pos, float v_size) :
	m_LookAt(sf::Lines, 2), m_LookAtSide(sf::Lines, 2), m_Front(1, 0), m_Side(0, 1) 
{
	PlayerObject.setPosition(v_pos);
	PlayerObject.setRadius(v_size);
	PlayerObject.setOrigin(sf::Vector2f(v_size, v_size));
	PlayerObject.setOutlineThickness(1);
	PlayerObject.setOutlineColor(sf::Color(3, 166, 150));
	PlayerObject.setFillColor(sf::Color::Transparent);

	m_LookAt[0].position.x = PlayerObject.getPosition().x;
	m_LookAt[0].position.y = PlayerObject.getPosition().y;
	m_LookAt[1].position.x = PlayerObject.getPosition().x + (m_Front.x * PlayerObject.getRadius());
	m_LookAt[1].position.y = PlayerObject.getPosition().y + (m_Front.y * PlayerObject.getRadius());
	m_LookAt[0].color = sf::Color(166, 55, 3);
	m_LookAt[1].color = sf::Color(166, 55, 3);

	m_LookAtSide[0].position.x = PlayerObject.getPosition().x;
	m_LookAtSide[0].position.y = PlayerObject.getPosition().y;
	m_LookAtSide[1].position.x = PlayerObject.getPosition().x + (m_Side.x * PlayerObject.getRadius());
	m_LookAtSide[1].position.y = PlayerObject.getPosition().y + (m_Side.y * PlayerObject.getRadius());
	m_LookAtSide[0].color = sf::Color(127, 255, 107);
	m_LookAtSide[1].color = sf::Color(127, 255, 107);

	playerRotation();
}

Player::~Player()
{}

void Player::update(const float& v_deltaTime)
{
	playerMovment(v_deltaTime);
	playerRotation();
}

const sf::Vector2f Player::getStartPointForRay(const float& v_rotation, const float& v_rayLength) const
{
	return sf::Vector2f(PlayerObject.getPosition().x + std::sin((PlayerObject.getRotation() + v_rotation) * M_PI / 180) * v_rayLength,
						PlayerObject.getPosition().y + std::cos((PlayerObject.getRotation() + v_rotation) * M_PI / 180) * v_rayLength);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(PlayerObject);
	target.draw(m_LookAt);
	target.draw(m_LookAtSide);
}

void Player::playerMovment(const float& v_deltaTime)
{
	sf::Vector2f moveby(0, 0);
	bool Front = false;
	bool Side = false;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		moveby.x += m_Front.x * m_MoveSpeed * v_deltaTime;
		moveby.y += m_Front.y * m_MoveSpeed * v_deltaTime;
		Front = true;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		moveby.x += -(m_Front.x * m_MoveSpeed * v_deltaTime);
		moveby.y += -(m_Front.y * m_MoveSpeed * v_deltaTime);
		Front = true;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		moveby.x += m_Side.x * m_MoveSpeed * v_deltaTime;
		moveby.y += m_Side.y * m_MoveSpeed * v_deltaTime;
		Side = true;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		moveby.x += -(m_Side.x * m_MoveSpeed * v_deltaTime);
		moveby.y += -(m_Side.y * m_MoveSpeed * v_deltaTime);
		Side = true;
	}

	if(Front && Side)
	{
		moveby.x /= 1.5f;
		moveby.y /= 1.5f;
	}

	PlayerObject.move(moveby);
	m_LookAt[0].position.x = PlayerObject.getPosition().x;
	m_LookAt[0].position.y = PlayerObject.getPosition().y;
	m_LookAtSide[0].position.x = PlayerObject.getPosition().x;
	m_LookAtSide[0].position.y = PlayerObject.getPosition().y;
}

void Player::playerRotation()
{
	float Roatation = DeltaMouse.x;
	PlayerObject.rotate(-Roatation * m_RotationSpeed);

	m_Front.x = std::sin(PlayerObject.getRotation() * M_PI / 180);
	m_Front.y = std::cos(PlayerObject.getRotation() * M_PI / 180);
	m_Side.x = std::sin((PlayerObject.getRotation() + 90) * M_PI / 180);
	m_Side.y = std::cos((PlayerObject.getRotation() + 90) * M_PI / 180);

	m_LookAt[1].position.x = PlayerObject.getPosition().x + m_Front.x * PlayerObject.getRadius();
	m_LookAt[1].position.y = PlayerObject.getPosition().y + m_Front.y * PlayerObject.getRadius();

	m_LookAtSide[1].position.x = PlayerObject.getPosition().x + m_Side.x * PlayerObject.getRadius();
	m_LookAtSide[1].position.y = PlayerObject.getPosition().y + m_Side.y * PlayerObject.getRadius();
}
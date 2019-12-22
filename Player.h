#pragma once
#include <SFML/Graphics.hpp>

#define M_PI 3.14159265358979323846  

class Player : public sf::Drawable
{
public:
	sf::CircleShape PlayerObject;
	float m_Pov = 60.0f;
	sf::Vector2i DeltaMouse;

public:
	Player(sf::Vector2f v_pos, float v_size);
	~Player();
	
	void update(const float& v_deltaTime);

	const sf::Vector2f getStartPointForRay(const float& v_rotation, const float& v_rayLength) const;
	const sf::Vector2f getLookAt() const { return m_Front; }

private:
	float m_MoveSpeed = 150;
	float m_RotationSpeed = 0.1;
	sf::VertexArray m_LookAt;
	sf::VertexArray m_LookAtSide;
	sf::Vector2f m_Front;
	sf::Vector2f m_Side;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void playerMovment(const float& v_deltaTime);
	void playerRotation();
};
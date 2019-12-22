#pragma once
#include <SFML/Graphics.hpp>

sf::Vector2f AddVectors(const sf::Vector2f v_vec1, const sf::Vector2f v_vec2);

sf::Vector2f SubVectors(const sf::Vector2f v_vec1, const sf::Vector2f v_vec2);

sf::Vector2f ScaleVector(const sf::Vector2f v_vec1, const float scalar);

float GetVectorLength(const sf::Vector2f v_vec1);

sf::Vector2f GetUnitVector(const sf::Vector2f v_vec1);

float DotProduct(const sf::Vector2f v_vec1, const sf::Vector2f v_vec2);

float AngleBetweenVectors(const sf::Vector2f v_vec1, const sf::Vector2f v_vec2);

sf::Vector2f getVectorProjection(const sf::Vector2f v_vec1, const sf::Vector2f v_vec2);

float getVectorProjectionLength(const sf::Vector2f v_vec1, const sf::Vector2f v_vec2);

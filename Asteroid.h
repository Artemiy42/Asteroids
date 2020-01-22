#pragma once

#include <SFML\Graphics.hpp>

class Asteroid : public sf::Sprite
{
public:
	const float kMaxSpeed = 800.0f;

	Asteroid();
	~Asteroid();
	void update(float deltaTime);
	void moveAsteroid(sf::Vector2f vectorSpeed);
	void getType();

private:
	sf::Texture m_texture;
	sf::Vector2f m_vectorSpeed;
};
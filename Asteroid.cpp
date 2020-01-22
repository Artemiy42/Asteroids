#include "Asteroid.h"

Asteroid::Asteroid()
{
	m_texture.loadFromFile("res\\img\\Asteroid.png");
	setTexture(m_texture);
	setPosition(20, 100);
	float valueRotation = (rand() % 360) * 3.14f / 180;
	sf::Vector2f vectorDirection = sf::Vector2f(sin(valueRotation), -cos(valueRotation));
	m_vectorSpeed = vectorDirection * float(rand() % 100 + 100);
}

Asteroid::~Asteroid()
{

}

void Asteroid::update(float deltaTime)
{
	moveAsteroid(m_vectorSpeed * deltaTime);
}

void Asteroid::moveAsteroid(sf::Vector2f vectorSpeed)
{
	sf::Vector2f asteroidPosition = getPosition();

	asteroidPosition += vectorSpeed;

	if (asteroidPosition.x > 800) asteroidPosition.x = 0;
	if (asteroidPosition.x < 0)	asteroidPosition.x = 800;
	if (asteroidPosition.y > 800) asteroidPosition.y = 0;
	if (asteroidPosition.y < 0) asteroidPosition.y = 800;

	setPosition(asteroidPosition);
}
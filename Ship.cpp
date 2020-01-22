#include "Ship.h"
#include <cmath>

Ship::Ship()
{	
	m_texture.loadFromFile("res\\img\\Ship.png");
	setTexture(m_texture);
	setPosition(300, 500);
	setOrigin(8, 13);
	m_vectorSpeed = { 0, 0 };
}

void Ship::update(float deltaTime)
{
	if (m_bullet.isAlive())
		m_bullet.update(deltaTime);

	moveShip(m_vectorSpeed * deltaTime);

	m_vectorSpeed -= m_vectorSpeed * kResistance;
}

void Ship::addForce()
{
	float valueRotation = getRotation() * 3.14f / 180;
	sf::Vector2f vectorDirection = sf::Vector2f(sin(valueRotation), -cos(valueRotation));
	sf::Vector2f newVectorSpeed = m_vectorSpeed + vectorDirection * kAcceleration;

	if (abs(newVectorSpeed.x) < kMaxSpeed && abs(newVectorSpeed.y) < kMaxSpeed)
		m_vectorSpeed = newVectorSpeed;
}

void Ship::moveShip(sf::Vector2f vectorSpeed)
{
	sf::Vector2f shipPosition = getPosition();

	shipPosition += vectorSpeed;

	if (shipPosition.x > 800) shipPosition.x = 0;
	if (shipPosition.x < 0)	shipPosition.x = 800;
	if (shipPosition.y > 800) shipPosition.y = 0;
	if (shipPosition.y < 0) shipPosition.y = 800;
	
	setPosition(shipPosition);
}

void Ship::fire()
{
	m_bullet.setPosition(getPosition());

	float valueRotation = getRotation() * 3.14f / 180;
	sf::Vector2f vectorDirection = sf::Vector2f(sin(valueRotation), -cos(valueRotation));

	m_bullet.setSpeed(vectorDirection);
	m_bullet.setRotation(getRotation());
	m_bullet.wakeUp();
}


Bullet* Ship::getBullet()
{
	return &m_bullet;
}
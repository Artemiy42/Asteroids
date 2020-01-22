#pragma once

#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Ship : public sf::Sprite
{
public:
	const float kResistance = 0.01f;
	const float kAcceleration = 10.0f;
	const float kMaxSpeed = 800.0f;
	const float kAngleRotation = 5.0f;

	Ship();
	void update(float deltaTime);
	void addForce();
	void moveShip(sf::Vector2f vectorSpeed);
	void fire();
	Bullet* getBullet();

private:
	sf::Texture m_texture;
	sf::Vector2f m_vectorSpeed;

	Bullet m_bullet;
};
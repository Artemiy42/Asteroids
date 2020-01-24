#pragma once

#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Ship : public sf::Sprite
{
public:
	const float kResistance = 0.009f;
	const float kAcceleration = 10.0f;
	const float kMaxSpeed = 800.0f;
	const float kAngleRotation = 3.0f;
	const float kCooldownFire = 0.2f;

public:
	Ship();
	void update(float deltaTime);
	void render(sf::RenderWindow*& renderWindow);
	void addForce();
	void moveShip(sf::Vector2f vectorSpeed);
	bool isFire();
	void fire(Bullet& bullet);

private:
	sf::Texture m_texture;
	sf::Vector2f m_vectorSpeed;
	float m_timeCooldown;
	bool m_isFire;
};
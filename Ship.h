#pragma once

#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Ship : public sf::Sprite
{
public:
	static const float kResistance;
	static const float kAccelerationShip;
	static const float kMaxSpeedShip;
	static const float kAngleRotation;
	static const float kCooldownFire;

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
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	void render(sf::RenderWindow* renderWindow);
	void addForce();
	void move(sf::Vector2f vectorSpeed);
	bool isFire();
	bool isAlive();
	void die();
	void live();
	void fire(Bullet& bullet);

private:
	sf::Texture m_texture;
	sf::Vector2f m_vectorSpeed;
	sf::Sound sound;
	float m_timeCooldown;
	bool m_isFire;
	bool m_isAlive;
};
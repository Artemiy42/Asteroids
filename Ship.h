#pragma once

#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Ship : public sf::Drawable, public sf::Transformable
{
public:
	const float kResistance = 0.01f;
	const float kAcceleration = 10.0f;
	const float kMaxSpeed = 800.0f;
	const float kAngleRotation = 5.0f;

public:
	Ship();
	void update(float deltaTime);
	void addForce();
	void moveShip(sf::Vector2f vectorSpeed);
	void fire(Bullet& bullet);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_vectorSpeed;
};
#pragma once

#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite
{
public:
	const float kMaxDistance = 500.0f;

	Bullet();
	~Bullet();
	void update(float deltaTime);
	void moveBullet(sf::Vector2f vectorSpeed);
	void setSpeed(sf::Vector2f direction);
	bool isAlive();
	void wakeUp();
	void die();

private:
	sf::Texture m_texture;
	sf::Vector2f m_vectorSpeed;
	float m_lengthVectorSpeed;
	float m_distance;
	bool m_isAlive;
};
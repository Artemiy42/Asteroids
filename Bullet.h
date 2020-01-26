#pragma once

#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite
{
public:
	static const float kMaxDistance;
	static const float kAccelerationBullet;
	
	Bullet();
	~Bullet();
	void update(float deltaTime);
	void move(sf::Vector2f vectorSpeed);
	bool isAlive() const;
	void wakeUp();
	void die();
	void render(sf::RenderWindow* renderWindow);

private:
	sf::Texture m_texture;
	sf::Vector2f m_vectorSpeed;
	float m_distance;
	bool m_isAlive;
};

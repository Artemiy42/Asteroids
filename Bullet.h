#pragma once

#include <SFML/Graphics.hpp>

class Bullet : public sf::Drawable, public sf::Transformable
{
public:
	const float kMaxDistance = 500.0f;
	const float kAcceleration = 10.0f;
	
	Bullet();
	~Bullet();
	void update(float deltaTime);
	void moveBullet(sf::Vector2f vectorSpeed);
	bool isAlive() const;
	void wakeUp();
	void die();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_vectorSpeed;
	float m_distance;
	bool m_isAlive;
};
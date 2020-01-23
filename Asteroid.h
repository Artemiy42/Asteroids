#pragma once

#include <SFML\Graphics.hpp>

class Asteroid : public sf::Drawable, public sf::Transformable
{
public:
	const int kMaxSpeed = 250;
	const int kMinSpped = 100;

	Asteroid();
	~Asteroid();
	void update(float deltaTime);
	void moveAsteroid(sf::Vector2f vectorSpeed);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2f m_vectorSpeed;
};
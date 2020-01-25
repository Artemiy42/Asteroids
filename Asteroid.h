#pragma once

#include <SFML\Graphics.hpp>

enum class AsteroidType
{
	Small,
	Big
};

class Asteroid : public sf::Sprite
{
public:
	static const int kMaxSpeed = 350;
	static const int kMinSpped = 100;

	Asteroid();
	Asteroid(AsteroidType type, sf::Vector2f position);
	~Asteroid();
	void update(float deltaTime);
	void render(sf::RenderWindow*& renderWindow);
	void moveAsteroid(sf::Vector2f vectorSpeed);
	AsteroidType getType();

private:
	sf::Texture m_texture;
	sf::Vector2f m_vectorSpeed;
	AsteroidType m_type;

private:
	sf::Image getImageByType(AsteroidType type);
};
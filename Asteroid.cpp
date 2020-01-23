#include "Asteroid.h"
#include "UtilsForVector.h"
#include "Assets.h"

Asteroid::Asteroid()
{
	m_texture.loadFromImage(Assets::Instance().getAsteroid());
	m_sprite.setTexture(m_texture);
	m_vectorSpeed = vectorDirection(rand() % 360) * float(rand() % (kMaxSpeed - kMinSpped) + kMinSpped);
}

Asteroid::~Asteroid()
{

}

void Asteroid::update(float deltaTime)
{
	moveAsteroid(m_vectorSpeed * deltaTime);
}

void Asteroid::moveAsteroid(sf::Vector2f vectorSpeed)
{
	sf::Vector2f asteroidPosition = getPosition();

	asteroidPosition += vectorSpeed;

	if (asteroidPosition.x > 800) asteroidPosition.x = 0;
	if (asteroidPosition.x < 0)	asteroidPosition.x = 800;
	if (asteroidPosition.y > 800) asteroidPosition.y = 0;
	if (asteroidPosition.y < 0) asteroidPosition.y = 800;

	setPosition(asteroidPosition);
}

void Asteroid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(m_sprite, states);
}
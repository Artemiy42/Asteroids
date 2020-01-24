#include "Asteroid.h"
#include "UtilsForVector.h"
#include "Assets.h"

Asteroid::Asteroid()
{
	m_type = AsteroidType(rand() % 2);
	m_texture.loadFromImage(getImageByType(m_type));
	setTexture(m_texture);
	setPosition(float(rand() % 800), float(rand() % 800));
	m_vectorSpeed = vectorDirection(rand() % 360) * float(rand() % (kMaxSpeed - kMinSpped) + kMinSpped);
}

Asteroid::Asteroid(AsteroidType type, sf::Vector2f position)
{
	m_type = type;
	m_texture.loadFromImage(getImageByType(m_type));
	setTexture(m_texture);
	setPosition(position);
	m_vectorSpeed = vectorDirection(rand() % 360) * float(rand() % (kMaxSpeed - kMinSpped) + kMinSpped);
}

Asteroid::~Asteroid()
{

}

void Asteroid::update(float deltaTime)
{
	moveAsteroid(m_vectorSpeed * deltaTime);
}

void Asteroid::render(sf::RenderWindow*& renderWindow)
{
	renderWindow->draw(*this);
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

AsteroidType Asteroid::getType()
{
	return m_type;
}

sf::Image Asteroid::getImageByType(AsteroidType type)
{
	if (type == AsteroidType::Small)
		return Assets::Instance().getCatAsteroidSmall();
	else if (type == AsteroidType::Big)
		return Assets::Instance().getCatAsteroidBig();
	else
		throw;
}

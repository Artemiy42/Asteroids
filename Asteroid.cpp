#include "Asteroid.h"
#include "UtilsForVector.h"
#include "Assets.h"
#include "Settings.h"

Asteroid::Asteroid()
{
	m_type = AsteroidType(rand() % 2);
	m_texture.loadFromImage(getImageByType(m_type));
	setTexture(m_texture);
	
	sf::Vector2f mapSize = Settings::Instance().getMapSize();
	setPosition(float(rand() % int(mapSize.x)), float(rand() % int(mapSize.y)));

	m_vectorSpeed = vectorDirection(rand() % 360) * float(rand() % (kMaxSpeed - kMinSpped) + kMinSpped);
	
	sf::IntRect textureRect = getTextureRect();
	setOrigin(textureRect.width / 2.f, textureRect.height / 2.f);
}

Asteroid::Asteroid(AsteroidType type, sf::Vector2f position)
{
	m_type = type;
	m_texture.loadFromImage(getImageByType(m_type));
	setTexture(m_texture);
	setPosition(position);
	m_vectorSpeed = vectorDirection(rand() % 360) * float(rand() % (kMaxSpeed - kMinSpped) + kMinSpped);
}

void Asteroid::update(float deltaTime)
{
	move(m_vectorSpeed * deltaTime);
}

void Asteroid::render(sf::RenderWindow* renderWindow)
{
	renderWindow->draw(*this);
}

void Asteroid::move(sf::Vector2f vectorSpeed)
{
	sf::Vector2f asteroidPosition = getPosition();
	sf::Vector2f mapSize = Settings::Instance().getMapSize();

	asteroidPosition += vectorSpeed;

	if (asteroidPosition.x > mapSize.x) asteroidPosition.x = 0;
	if (asteroidPosition.x < 0)	asteroidPosition.x = mapSize.x;
	if (asteroidPosition.y > mapSize.y) asteroidPosition.y = 0;
	if (asteroidPosition.y < 0) asteroidPosition.y = mapSize.y;

	setPosition(asteroidPosition);
}

void Asteroid::changeDirection(sf::FloatRect asteroidFloatRect)
{
	float firstAsteroidBottom = getGlobalBounds().top + getGlobalBounds().height;
	float secondAsteroidBottom = asteroidFloatRect.top + asteroidFloatRect.height;
	float firstAsteroidRight = getGlobalBounds().left + getGlobalBounds().width;
	float secondAsteroidRight = asteroidFloatRect.left + asteroidFloatRect.width;

	float bottomCollision = secondAsteroidBottom - getGlobalBounds().top;
	float topCollision = firstAsteroidBottom - asteroidFloatRect.top;
	float leftCollision = firstAsteroidRight - asteroidFloatRect.left;
	float rightCollision = secondAsteroidRight - getGlobalBounds().left;

	if (topCollision < bottomCollision && topCollision < leftCollision && topCollision < rightCollision)
	{
		float valueDirection = rand() % 180 + 90;

		valueDirection > 180 ? valueDirection += 90 : valueDirection += 180;

		m_vectorSpeed = vectorDirection(valueDirection)* float(rand() % (kMaxSpeed - kMinSpped) + kMinSpped);
	}
	
	if (bottomCollision < topCollision && bottomCollision < leftCollision && bottomCollision < rightCollision)
	{
		m_vectorSpeed = vectorDirection(rand() % 180 + 90) * float(rand() % (kMaxSpeed - kMinSpped) + kMinSpped);
	}
	
	if (leftCollision < rightCollision && leftCollision < topCollision && leftCollision < bottomCollision)
	{
		m_vectorSpeed = vectorDirection(rand() % 180 + 180) * float(rand() % (kMaxSpeed - kMinSpped) + kMinSpped);
	}
	
	if (rightCollision < leftCollision && rightCollision < topCollision && rightCollision < bottomCollision)
	{
		m_vectorSpeed = vectorDirection(rand() % 180) * float(rand() % (kMaxSpeed - kMinSpped) + kMinSpped);
	}
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

#include "Bullet.h"
#include "UtilsForVector.h"
#include "Assets.h"

Bullet::Bullet()
{
	m_texture.loadFromImage(Assets::Instance().getBullet());
	setTexture(m_texture);
	sf::IntRect textureRect = getTextureRect();
	setOrigin(textureRect.width / 2.f, textureRect.height / 2.f);
	m_isAlive = false;
	m_distance = 0.0f;
	m_vectorSpeed = { 0.0f, 0.0f };
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	if (m_isAlive)
	{
		moveBullet(m_vectorSpeed);

		m_distance += lengthVector(m_vectorSpeed);

		if (m_distance > kMaxDistance)
			die();
	}
}

void Bullet::moveBullet(sf::Vector2f vectorSpeed)
{
	sf::Vector2f bulletPosition = getPosition();

	bulletPosition += vectorSpeed;

	if (bulletPosition.x > 1000) bulletPosition.x = 0;
	if (bulletPosition.x < 0)	bulletPosition.x = 1000;
	if (bulletPosition.y > 1000) bulletPosition.y = 0;
	if (bulletPosition.y < 0) bulletPosition.y = 1000;

	setPosition(bulletPosition);
}

bool Bullet::isAlive() const
{
	return m_isAlive;
}

void Bullet::wakeUp()
{
	m_isAlive = true;
	m_distance = 0.0f;
	m_vectorSpeed = vectorDirection(getRotation()) * kAcceleration;
}

void Bullet::die()
{
	m_isAlive = false;
}

void Bullet::render(sf::RenderWindow*& renderWindow)
{
	if (m_isAlive)
	{
		renderWindow->draw(*this);
	}
}
#include "Bullet.h"
#include "UtilsForVector.h"

Bullet::Bullet()
{
	m_texture.loadFromFile("res\\img\\Bullet.png");
	setTexture(m_texture);
	setOrigin(1,2);
	m_isAlive = false;
	m_distance = 0;
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	moveBullet(m_vectorSpeed);

	m_distance += lengthVector(m_vectorSpeed);

	if (m_distance > kMaxDistance)
		die();
}

void Bullet::moveBullet(sf::Vector2f vectorSpeed)
{
	sf::Vector2f bulletPosition = getPosition();

	bulletPosition += vectorSpeed;

	if (bulletPosition.x > 800) bulletPosition.x = 0;
	if (bulletPosition.x < 0)	bulletPosition.x = 800;
	if (bulletPosition.y > 800) bulletPosition.y = 0;
	if (bulletPosition.y < 0) bulletPosition.y = 800;

	setPosition(bulletPosition);
}

bool Bullet::isAlive()
{
	return m_isAlive;
}

void Bullet::wakeUp()
{
	m_isAlive = true;
	m_distance = 0.0f;
}

void Bullet::die()
{
	m_isAlive = false;
}

void Bullet::setSpeed(sf::Vector2f direction)
{
	m_vectorSpeed = direction * 10.f;
}
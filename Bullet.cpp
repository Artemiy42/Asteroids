#include "Bullet.h"
#include "UtilsForVector.h"
#include "Assets.h"

Bullet::Bullet()
{
	m_texture.loadFromImage(Assets::Instance().getBullet());
	m_sprite.setTexture(m_texture);
	sf::IntRect textureRect = m_sprite.getTextureRect();
	setOrigin(textureRect.width / 2, textureRect.height / 2);
	m_isAlive = false;
	m_distance = 0;
	m_vectorSpeed = { 0, 0 };
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	if (isAlive())
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

	if (bulletPosition.x > 800) bulletPosition.x = 0;
	if (bulletPosition.x < 0)	bulletPosition.x = 800;
	if (bulletPosition.y > 800) bulletPosition.y = 0;
	if (bulletPosition.y < 0) bulletPosition.y = 800;

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

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (isAlive())
	{
		states.transform *= getTransform();

		target.draw(m_sprite, states);
	}
}
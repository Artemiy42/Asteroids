#include <cmath>
#include "Ship.h"
#include "Assets.h"
#include "UtilsForVector.h"

Ship::Ship()
{	
	m_texture.loadFromImage(Assets::Instance().getShip());
	setTexture(m_texture);
	setPosition(300, 500);
	sf::IntRect textureRect = getTextureRect();
	setOrigin(textureRect.width / 2.f, textureRect.height / 2.f);
	m_vectorSpeed = { 0, 0 };
	m_timeCooldown = 0;
	m_isFire = false;
}

void Ship::update(float deltaTime)
{
	moveShip(m_vectorSpeed * deltaTime);

	m_vectorSpeed -= m_vectorSpeed * kResistance;
	
	if (m_isFire)
	{
		if (m_timeCooldown < kCooldownFire)
			m_timeCooldown += deltaTime;
		else
		{
			m_isFire = false;
			m_timeCooldown = 0;
		}
	}
}

void Ship::render(sf::RenderWindow*& renderWindow)
{
	renderWindow->draw(*this);
}

void Ship::addForce()
{
	sf::Vector2f newVectorSpeed = m_vectorSpeed + vectorDirection(getRotation()) * kAcceleration;

	if (abs(newVectorSpeed.x) < kMaxSpeed && abs(newVectorSpeed.y) < kMaxSpeed)
		m_vectorSpeed = newVectorSpeed;
}

void Ship::moveShip(sf::Vector2f vectorSpeed)
{
	sf::Vector2f shipPosition = getPosition();

	shipPosition += vectorSpeed;

	if (shipPosition.x > 800) shipPosition.x = 0;
	if (shipPosition.x < 0)	shipPosition.x = 800;
	if (shipPosition.y > 800) shipPosition.y = 0;
	if (shipPosition.y < 0) shipPosition.y = 800;
	
	setPosition(shipPosition);
}

bool Ship::isFire()
{
	return m_isFire;
}

void Ship::fire(Bullet& bullet)
{
	if (!m_isFire)
	{
		bullet.setPosition(getPosition());
		bullet.setRotation(getRotation());
		bullet.wakeUp();
		m_isFire = true;
	}
}
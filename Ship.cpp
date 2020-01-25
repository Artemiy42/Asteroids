#include <cmath>
#include "Ship.h"
#include "Assets.h"
#include "UtilsForVector.h"
#include "Settings.h"

const float Ship::kResistance = 0.009f;
const float Ship::kAccelerationShip = 10.0f;
const float Ship::kMaxSpeedShip = 800.0f;
const float Ship::kAngleRotation = 3.0f;
const float Ship::kCooldownFire = 0.2f;

Ship::Ship()
{	
	m_texture.loadFromImage(Assets::Instance().getShip());
	setTexture(m_texture);
	
	sf::IntRect textureRect = getTextureRect();
	setOrigin(textureRect.width / 2.f, textureRect.height / 2.f);

	sf::Vector2f mapSize = Settings::Instance().getMapSize();
	mapSize.x /= 2;
	mapSize.y /= 2;
	setPosition(mapSize);
	
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
	sf::Vector2f newVectorSpeed = m_vectorSpeed + vectorDirection(getRotation()) * kAccelerationShip;

	if (abs(newVectorSpeed.x) < kMaxSpeedShip && abs(newVectorSpeed.y) < kMaxSpeedShip)
		m_vectorSpeed = newVectorSpeed;
}

void Ship::moveShip(sf::Vector2f vectorSpeed)
{
	sf::Vector2f shipPosition = getPosition();

	shipPosition += vectorSpeed;

	if (shipPosition.x > 1000) shipPosition.x = 0;
	if (shipPosition.x < 0)	shipPosition.x = 1000;
	if (shipPosition.y > 1000) shipPosition.y = 0;
	if (shipPosition.y < 0) shipPosition.y = 1000;
	
	setPosition(shipPosition);
}

bool Ship::isFire()
{
	return m_isFire;
}

void Ship::fire(Bullet& bullet)
{
	bullet.setPosition(getPosition());
	bullet.setRotation(getRotation());
	bullet.wakeUp();
	m_isFire = true;
}
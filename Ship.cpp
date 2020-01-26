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

	sound.setBuffer(Assets::Instance().getSoundBufferFire());
	
	sf::IntRect textureRect = getTextureRect();
	setOrigin(textureRect.width / 2.f, textureRect.height / 2.f);

	sf::Vector2f mapSize = Settings::Instance().getMapSize();
	mapSize.x /= 2;
	mapSize.y /= 2;
	setPosition(mapSize);
	
	m_vectorSpeed = { 0, 0 };
	m_timeCooldown = 0;
	m_isFire = false;
	m_isAlive = true;
}

void Ship::update(float deltaTime)
{
	move(m_vectorSpeed * deltaTime);

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

void Ship::render(sf::RenderWindow* renderWindow)
{
	renderWindow->draw(*this);
}

void Ship::addForce()
{
	sf::Vector2f newVectorSpeed = m_vectorSpeed + vectorDirection(getRotation()) * kAccelerationShip;

	if (abs(newVectorSpeed.x) < kMaxSpeedShip && abs(newVectorSpeed.y) < kMaxSpeedShip)
		m_vectorSpeed = newVectorSpeed;
}

void Ship::move(sf::Vector2f vectorSpeed)
{
	sf::Vector2f shipPosition = getPosition();
	sf::Vector2f mapSize = Settings::Instance().getMapSize();

	shipPosition += vectorSpeed;

	if (shipPosition.x > mapSize.x) shipPosition.x = 0;
	if (shipPosition.x < 0)	shipPosition.x = mapSize.x;
	if (shipPosition.y > mapSize.y) shipPosition.y = 0;
	if (shipPosition.y < 0) shipPosition.y = mapSize.y;
	
	setPosition(shipPosition);
}

bool Ship::isFire()
{
	return m_isFire;
}

bool Ship::isAlive()
{
	return m_isAlive;
}

void Ship::die()
{
	m_isAlive = false;
}

void Ship::fire(Bullet& bullet)
{
	bullet.setPosition(getPosition());
	bullet.setRotation(getRotation());
	bullet.wakeUp();
	sound.play();
	m_isFire = true;
}
#include <cmath>
#include "Ship.h"
#include "Assets.h"
#include "UtilsForVector.h"

Ship::Ship()
{	
	m_texture.loadFromImage(Assets::Instance().getShip());
	m_sprite.setTexture(m_texture);
	setPosition(300, 500);
	sf::IntRect textureRect = m_sprite.getTextureRect();
	setOrigin(textureRect.width / 2, textureRect.height / 2);
	m_vectorSpeed = { 0, 0 };
}

void Ship::update(float deltaTime)
{
	moveShip(m_vectorSpeed * deltaTime);

	m_vectorSpeed -= m_vectorSpeed * kResistance;
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

void Ship::fire(Bullet& bullet)
{
	bullet.setPosition(getPosition());
	bullet.setRotation(getRotation());
	bullet.wakeUp();
}

void Ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(m_sprite, states);
}
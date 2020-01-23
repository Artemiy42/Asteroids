#include "Assets.h"
#include "string"

void Assets::load()
{
	std::string path = "res\\img\\";

	if (!m_ship.loadFromFile(path + "Ship.png")) throw;
	if (!m_bullet.loadFromFile(path + "Bullet.png")) throw;
	if (!m_asteroid.loadFromFile(path + "Asteroid.png")) throw;
}

sf::Image Assets::getBullet()
{
	return m_bullet;
}

sf::Image Assets::getShip()
{
	return m_ship;
}

sf::Image Assets::getAsteroid()
{
	return m_asteroid;
}
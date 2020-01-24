#include "Assets.h"
#include "string"

void Assets::load()
{
	std::string path = "res\\img\\";

	if (!m_ship.loadFromFile(path + "Ship.png")) throw;
	if (!m_bullet.loadFromFile(path + "BulletFish.png")) throw;
	if (!m_catAsteroidSmall.loadFromFile(path + "catAsteroidSmall.png")) throw;
	if (!m_catAsteroidBig.loadFromFile(path + "catAsteroidBig.png")) throw;
}

sf::Image Assets::getBullet()
{
	return m_bullet;
}

sf::Image Assets::getShip()
{
	return m_ship;
}

sf::Image Assets::getCatAsteroidSmall()
{
	return m_catAsteroidSmall;
}

sf::Image Assets::getCatAsteroidBig()
{
	return m_catAsteroidBig;
}
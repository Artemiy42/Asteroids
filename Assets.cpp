#include "Assets.h"
#include "string"

void Assets::load()
{
	const static std::string pathImage = "res\\img\\";
	const static std::string pathFont = "res\\font\\";

	if (!m_ship.loadFromFile(pathImage + "Ship.png")) throw;
	if (!m_bullet.loadFromFile(pathImage + "BulletFish.png")) throw;
	if (!m_catAsteroidSmall.loadFromFile(pathImage + "catAsteroidSmall.png")) throw;
	if (!m_catAsteroidBig.loadFromFile(pathImage + "catAsteroidBig.png")) throw;
	if (!m_hyperSpaceFont.loadFromFile(pathFont + "Hyperspace.otf")) throw;
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

sf::Font& Assets::getHyperspaceFont()
{
	return m_hyperSpaceFont;
}

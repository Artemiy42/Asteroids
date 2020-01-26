#include <iostream>

#include "ArrayAsteroids.h"
#include "Collision.h"
#include "Score.h"

ArrayAsteroids::ArrayAsteroids()
{
	m_hasAliveAsteroid = true;
}

ArrayAsteroids::~ArrayAsteroids()
{
	for (std::list<Asteroid*>::iterator it = m_asteroids.begin(); it != m_asteroids.end(); it++)
	{
		delete *it;
	}
}

void ArrayAsteroids::initialize()
{
	if (m_asteroids.size() != 0)
	{
		for (std::list<Asteroid*>::iterator it = m_asteroids.begin(); it != m_asteroids.end(); it++)
		{
			delete *it;
		}
	}

	m_asteroids.clear();

	for (int i = 0; i < Settings::Instance().getNumberOfAsteroids(); i++)
	{
		m_asteroids.push_back(new Asteroid());
	}
}

void ArrayAsteroids::update(float deltaTime)
{
	for (std::list<Asteroid*>::iterator it = m_asteroids.begin(); it != m_asteroids.end(); it++)
	{
		(*it)->update(deltaTime);
	}
}

void ArrayAsteroids::render(sf::RenderWindow* renderWindow)
{
	for (std::list<Asteroid*>::iterator it = m_asteroids.begin(); it != m_asteroids.end(); it++)
	{
		(*it)->render(renderWindow);
	}
}

void ArrayAsteroids::intersects(Ship& ship, Magazine& magazine)
{
	std::list<Asteroid*>::iterator itAsteroid = m_asteroids.begin();
	
	while (itAsteroid != m_asteroids.end())
	{
		bool isDelete = false;

		if (Collision::PixelPerfectTest(ship, **itAsteroid))
		{
			ship.die();
		}

		for (std::list<Asteroid*>::iterator itOtherAsteroid = m_asteroids.begin(); itOtherAsteroid != m_asteroids.end(); itOtherAsteroid++)
		{
			if (itOtherAsteroid != itAsteroid && Collision::PixelPerfectTest(**itAsteroid, **itOtherAsteroid))
			{
				(*itAsteroid)->changeDirection((*itOtherAsteroid)->getGlobalBounds());
				(*itOtherAsteroid)->changeDirection((*itAsteroid)->getGlobalBounds());
			}
		}

		isDelete = intersectsWithBullet(itAsteroid, magazine);

		if (!isDelete)
			itAsteroid++;
	}
}

bool ArrayAsteroids::intersectsWithBullet(std::list<Asteroid*>::iterator& itAsteroid, Magazine& magazine)
{
	bool isDelete = false;
	std::vector<Bullet*> bulletArray = magazine.getAllBullets();

	for (std::vector<Bullet*>::iterator itBullet = bulletArray.begin(); itBullet < bulletArray.end(); itBullet++)
	{
		if ((*itAsteroid)->getGlobalBounds().intersects((*itBullet)->getGlobalBounds()) && (*itBullet)->isAlive())
		{
			if ((*itAsteroid)->getType() == AsteroidType::Big)
			{
				m_asteroids.push_back(new Asteroid(AsteroidType::Small, (*itAsteroid)->getPosition()));
				m_asteroids.push_back(new Asteroid(AsteroidType::Small, (*itAsteroid)->getPosition()));
			}

			(*itBullet)->die();
			Score::Instance().addPoints((*itAsteroid)->getType());
			delete *itAsteroid;
			itAsteroid = m_asteroids.erase(itAsteroid);
			isDelete = true;

			break;
		}
	}
	
	return isDelete;
}

bool ArrayAsteroids::hasAliveAsteroid()
{
	return m_asteroids.size() != 0;
}

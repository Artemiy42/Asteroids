#include <iostream>

#include "ArrayAsteroids.h"
#include "Collision.h"

ArrayAsteroids::ArrayAsteroids()
{
	m_hasAliveAsteroid = true;
	
	for (int i = 0; i < kDefaultQuantityAsteroids; i++)
	{
		m_asteroids.push_back(new Asteroid());
	}
}


ArrayAsteroids::ArrayAsteroids(unsigned int amount)
{
	if (amount > kMaxQuantityAsteroids)
	{
		amount = kMaxQuantityAsteroids;
	}
	
	m_hasAliveAsteroid = true;

	for (int i = 0; i < amount; i++)
	{
		m_asteroids.push_back(new Asteroid());
	}
}

ArrayAsteroids::~ArrayAsteroids()
{
	for (std::list<Asteroid*>::iterator it = m_asteroids.begin(); it != m_asteroids.end(); it++)
	{
		delete *it;
	}
}

void ArrayAsteroids::update(float deltaTime)
{
	for (std::list<Asteroid*>::iterator it = m_asteroids.begin(); it != m_asteroids.end(); it++)
	{
		(*it)->update(deltaTime);
	}
}

void ArrayAsteroids::render(sf::RenderWindow*& renderWindow)
{
	for (std::list<Asteroid*>::iterator it = m_asteroids.begin(); it != m_asteroids.end(); it++)
	{
		(*it)->render(renderWindow);
	}
}

void ArrayAsteroids::intersects(Ship& ship, Magazine& magazine)
{
	std::list<Asteroid*>::iterator it = m_asteroids.begin();
	Bullet* bulletArray = magazine.getAllBullets();
	while (it != m_asteroids.end())
	{
		bool isDelete = false;

		if (Collision::PixelPerfectTest(ship, **it))
		{
			std::cout << "Collision ship with asteroid" << std::endl;
		}

		for (int indexBullet = 0; indexBullet < magazine.getAmountBullets(); indexBullet++)
		{
			if ((*it)->getGlobalBounds().intersects(bulletArray[indexBullet].getGlobalBounds()) && bulletArray[indexBullet].isAlive())
			{
				std::cout << "Collision bullet with asteroid" << std::endl;
				if ((*it)->getType() == AsteroidType::Big)
				{
					m_asteroids.push_back(new Asteroid(AsteroidType::Small, (*it)->getPosition()));
					m_asteroids.push_back(new Asteroid(AsteroidType::Small, (*it)->getPosition()));
				}
				
				bulletArray[indexBullet].die();
				it = m_asteroids.erase(it);
				isDelete = true;
				
				break;
			}
		}

		if (!isDelete)
			it++;
	}
}

bool ArrayAsteroids::hasAliveAsteroid()
{
	return m_asteroids.size() != 0;
}
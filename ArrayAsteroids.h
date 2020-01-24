#pragma once

#include <list>

#include "Asteroid.h"
#include "Magazine.h"
#include "Ship.h"

class ArrayAsteroids
{
public:
	const unsigned int kMaxQuantityAsteroids = 100;
	const unsigned int kDefaultQuantityAsteroids = 10;

public:
	ArrayAsteroids();
	ArrayAsteroids(unsigned int amount);
	~ArrayAsteroids();
	void update(float deltaTime);
	void render(sf::RenderWindow*& renderWindow);
	void intersects(Ship& ship, Magazine& magazine);
	bool hasAliveAsteroid();

private:
	std::list<Asteroid*> m_asteroids;
	bool m_hasAliveAsteroid;

};
#pragma once

#include <list>

#include "Asteroid.h"
#include "Magazine.h"
#include "Ship.h"
#include "Settings.h"

class ArrayAsteroids
{
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
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
	void render(sf::RenderWindow* renderWindow);
	void intersects(Ship& ship, Magazine& magazine);
	bool hasAliveAsteroid();

private:
	bool intersectsWithBullet(std::list<Asteroid*>::iterator& itAsteroid, Magazine& magazine);

private:
	std::list<Asteroid*> m_asteroids;
	bool m_hasAliveAsteroid;

};
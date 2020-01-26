#pragma once

#include <vector>

#include "Bullet.h"
#include "Settings.h"

class Magazine
{
public:
	Magazine();
	~Magazine();

	void update(float deltaTime);
	void render(sf::RenderWindow* renderWindow);
	Bullet& getNextBullet();
	std::vector<Bullet*> getAllBullets();

private:
	std::vector<Bullet*> m_bullets;
	unsigned int m_lastBullet;
};


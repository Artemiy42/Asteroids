#pragma once

#include "Bullet.h"
#include "Settings.h"

class Magazine
{
public:
	Magazine();
	Magazine(unsigned int amount);
	~Magazine();

	void update(float deltaTime);
	void render(sf::RenderWindow*& renderWindow);
	Bullet& getNextBullet();
	Bullet* getAllBullets();
	unsigned int getAmountBullets();

private:
	Bullet* m_bullets;
	unsigned int m_amount;
	unsigned int m_lastBullet;
};


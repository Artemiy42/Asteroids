#pragma once

#include "Bullet.h"

class Magazine
{
public:
	const unsigned int kMaxQuantityBullet = 20;
	const unsigned int kDefaultQuantityBullet = 4;

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


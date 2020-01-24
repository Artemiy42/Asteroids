#include "Magazine.h"

Magazine::Magazine()
{
	m_lastBullet = 0;
	m_amount = kDefaultQuantityBullet;
	m_bullets = new Bullet[kDefaultQuantityBullet];
}

Magazine::Magazine(unsigned int amount)
{
	if (amount < kMaxQuantityBullet)
		m_amount = amount;
	else
		m_amount = kMaxQuantityBullet;
	
	m_lastBullet = 0;
	m_bullets = new Bullet[m_amount];
}

Magazine::~Magazine()
{
	delete[] m_bullets;
}

void Magazine::update(float deltaTime)
{
	for (int i = 0; i < m_amount; i++)
	{
		m_bullets[i].update(deltaTime);
	}
}

void Magazine::render(sf::RenderWindow*& renderWindow)
{
	for (int i = 0; i < m_amount; i++)
	{
		m_bullets[i].render(renderWindow);
	}
}

Bullet& Magazine::getNextBullet()
{
	if (m_lastBullet >= m_amount - 1)
		m_lastBullet = 0;

	return m_bullets[m_lastBullet++];
}

Bullet* Magazine::getAllBullets()
{
	return m_bullets;
}


unsigned int Magazine::getAmountBullets() { return m_amount; }
#include "Magazine.h"
#include <iostream>

Magazine::Magazine()
{
	m_lastBullet = 0;
	m_amount = Settings::Instance().getNumberOfAmmo();
	m_bullets = new Bullet[m_amount];
}

Magazine::Magazine(unsigned int amount)
{
	if (amount < Settings::kMaxNumberOfAmmo)
		m_amount = amount;
	else
		m_amount = Settings::kMaxNumberOfAmmo;
	
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
	std::cout << m_lastBullet << std::endl;
	return m_bullets[m_lastBullet++];
}

Bullet* Magazine::getAllBullets()
{
	return m_bullets;
}


unsigned int Magazine::getAmountBullets() { return m_amount; }
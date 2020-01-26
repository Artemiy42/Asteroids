#include "Magazine.h"
#include <iostream>

Magazine::Magazine()
{
	m_lastBullet = 0;

	for (int i = 0; i < Settings::Instance().getNumberOfAmmo(); i++)
	{
		m_bullets.push_back(new Bullet());
	}
}

Magazine::~Magazine()
{
	for (std::vector<Bullet*>::iterator it = m_bullets.begin(); it < m_bullets.end(); it++)
	{
		delete *it;
	}
}

void Magazine::update(float deltaTime)
{
	for (std::vector<Bullet*>::iterator it = m_bullets.begin(); it < m_bullets.end(); it++)
	{
		(*it)->update(deltaTime);
	}
}

void Magazine::render(sf::RenderWindow* renderWindow)
{
	for (std::vector<Bullet*>::iterator it = m_bullets.begin(); it < m_bullets.end(); it++)
	{
		(*it)->render(renderWindow);
	}
}

Bullet& Magazine::getNextBullet()
{
	if (m_lastBullet >= m_bullets.size() - 1)
		m_lastBullet = 0;

	std::cout << m_lastBullet << std::endl;
	
	return *m_bullets[m_lastBullet++];
}

std::vector<Bullet*> Magazine::getAllBullets()
{
	return m_bullets;
}
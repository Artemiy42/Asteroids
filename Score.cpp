#include <string>

#include "Score.h"
#include "Assets.h"
#include "Settings.h"

Score::Score()
{
	m_scoreText.setFont(Assets::Instance().getHyperspaceFont());
	m_scoreText.setFillColor(sf::Color::White);
	m_scoreText.setCharacterSize(42);
	m_scoreText.setPosition(10.f, 10.f);
	m_numberOfPoints = 0;
}

void Score::addPoints(AsteroidType asteroidType)
{
	if (asteroidType == AsteroidType::Big)
		m_numberOfPoints += 50;
	else if (asteroidType == AsteroidType::Small)
		m_numberOfPoints += 100;
}

void Score::render(sf::RenderWindow* renderWindow)
{	
	m_scoreText.setString(std::to_string(m_numberOfPoints));

	renderWindow->draw(m_scoreText);
}

sf::Text& Score::getText()
{
	m_scoreText.setString(m_numberOfPoints);
	return m_scoreText;
}
#pragma once

#include <SFML\Graphics.hpp>

#include "AsteroidType.h"

class Score
{
public:
	static Score& Instance()
	{
		static Score s;
		
		return s;
	}

	void render(sf::RenderWindow* renderWindow);
	void addPoints(AsteroidType asteroidType);
	sf::Text& getText();
	void scoreZero();

private:
	sf::Text m_scoreText;
	unsigned int m_numberOfPoints;
	
private:
	Score();
	~Score() {};
	
	Score(Score const &) = delete;
	Score& operator= (Score const &) = delete;
};


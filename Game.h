#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>
#include <list>

#include "InputHandler.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Magazine.h"
#include "ArrayAsteroids.h"

class Game
{
public:
	Game();
	~Game();
	
	void setupSystem();
	void initialize();
	bool loop();
	void shutdown();

private:
	void render();
	void update(float deltaTime);

	bool m_isGameActive;
	clock_t m_clockLastFrame;

	sf::RenderWindow* m_renderWindow;
	Ship m_ship;
	ArrayAsteroids m_asteroids;

	sf::View m_viewShip;
	sf::View m_viewScore;
	sf::RectangleShape border;

	InputHandler m_inputHandler;
};
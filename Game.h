#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>
#include <list>

#include "Ship.h"
#include "Asteroid.h"

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
	Bullet m_bullet;
	std::list<Asteroid*> m_asteroids;
};
#include "Game.h"
#include <cstdlib>
#include <iostream>
#include "Collision.h"

Game::Game()
{
	m_isGameActive = true;
	m_clockLastFrame = 0;
	m_renderWindow = nullptr;
}

Game::~Game()
{
	delete m_renderWindow;
}

void Game::setupSystem()
{
	srand(time(0));
	m_renderWindow = new sf::RenderWindow(
		sf::VideoMode(800, 800),
		"Asteroids",
		sf::Style::Titlebar | sf::Style::Close);
	m_renderWindow->setFramerateLimit(60);
}

void Game::initialize()
{
	m_isGameActive = true;
}

bool Game::loop()
{
	if (m_renderWindow != nullptr && !m_renderWindow->isOpen())
		return false;

	clock_t clockNew = clock();
	clock_t deltaClock = clockNew - m_clockLastFrame;
	float deltaTime = float(deltaClock) / CLOCKS_PER_SEC;

	m_clockLastFrame = clockNew;

	sf::Event event;
	while (m_renderWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_renderWindow->close();
	}

	render();
	update(deltaTime);

	return m_isGameActive;
}

void Game::render()
{
	m_renderWindow->clear();
	m_ship.render(m_renderWindow);
	m_magazine.render(m_renderWindow);
	m_asteroids.render(m_renderWindow);
	m_renderWindow->display();
}

void Game::update(float deltaTime)
{
	m_ship.update(deltaTime);
	m_magazine.update(deltaTime);
	m_asteroids.update(deltaTime);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		m_ship.rotate(-m_ship.kAngleRotation);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		m_ship.rotate(m_ship.kAngleRotation);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		m_ship.addForce();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		m_ship.fire(m_magazine.getNextBullet());
	
	m_asteroids.intersects(m_ship, m_magazine);
	
	m_isGameActive = m_asteroids.hasAliveAsteroid();
}

void Game::shutdown()
{

}
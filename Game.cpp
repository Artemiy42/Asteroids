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
	for (std::list<Asteroid*>::iterator it = m_asteroids.begin(); it != m_asteroids.end(); it++)
	{
		delete *it;
	}

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

	for (int i = 0; i < 10; i++)
	{
		m_asteroids.push_back(new Asteroid());
	}
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

	return true;
}

void Game::render()
{
	m_renderWindow->clear();
	m_renderWindow->draw(m_ship);
	m_renderWindow->draw(m_bullet);
	
	for (std::list<Asteroid*>::iterator it = m_asteroids.begin(); it != m_asteroids.end(); it++)
	{
		m_renderWindow->draw(**it);
	}

	m_renderWindow->display();
}

void Game::update(float deltaTime)
{
	m_ship.update(deltaTime);
	m_bullet.update(deltaTime);

	for (std::list<Asteroid*>::iterator it = m_asteroids.begin(); it != m_asteroids.end(); it++)
	{
		(*it)->update(deltaTime);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		m_ship.rotate(-m_ship.kAngleRotation);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		m_ship.rotate(m_ship.kAngleRotation);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		m_ship.addForce();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		m_ship.fire(m_bullet);
	/*
	std::list<Asteroid*>::iterator it = m_asteroids.begin();
	while (it != m_asteroids.end())
	{
		if (Collision::PixelPerfectTest(m_ship, **it))
		{
			std::cout << "Collision ship with asteroid" << std::endl;
		}
		
		if (m_bullet.get getGlobalBounds().intersects((*it)->getGlobalBounds()))
		{
			m_asteroids.erase(it++);
			m_asteroids.push_back(new Asteroid());
		}
		else
			++it;
	}*/

	
}

void Game::shutdown()
{

}
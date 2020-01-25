#include "Game.h"
#include <cstdlib>
#include <iostream>
#include "Collision.h"
#include "Settings.h"

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

	sf::VideoMode videoMode = Settings::Instance().getVideoMode();
	m_renderWindow = new sf::RenderWindow(
		videoMode,
		"Asteroids",
		sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	m_renderWindow->setFramerateLimit(60);

	m_view = sf::View(sf::Vector2f(0.f, 0.f), sf::Vector2f(videoMode.width, videoMode.height));

	border.setSize(Settings::Instance().getMapSize());
	border.setPosition(0, 0);
	border.setOutlineThickness(5);
	border.setFillColor(sf::Color::Black);
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
		else if (event.type == sf::Event::Resized)
		{
			float aspectRadio = float(m_renderWindow->getSize().x) / float(m_renderWindow->getSize().y);
			sf::Vector2f mapSize = Settings::Instance().getMapSize();
			
			mapSize.x *= aspectRadio;
			m_view.setSize(mapSize);
		}
	}

	render();
	update(deltaTime);

	return m_isGameActive;
}

void Game::render()
{
	m_renderWindow->clear();
	m_renderWindow->setView(m_view);
	m_renderWindow->draw(border);
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
 		if (!m_ship.isFire())
			m_ship.fire(m_magazine.getNextBullet());
	
	m_view.setCenter(m_ship.getPosition());
	m_asteroids.intersects(m_ship, m_magazine);
	m_isGameActive = m_asteroids.hasAliveAsteroid();
}

void Game::shutdown()
{

}
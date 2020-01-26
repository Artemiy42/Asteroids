#include <iostream>
#include <cstdlib>

#include "Game.h"
#include "Collision.h"
#include "Settings.h"
#include "Score.h"

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
		Settings::Instance().getVideoMode(),
		"Asteroids",
		sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	m_renderWindow->setFramerateLimit(60);

	sf::Vector2f videoModeSize = Settings::Instance().getSizeVideoMode();

	m_viewShip = sf::View(sf::Vector2f(0.f, 0.f), videoModeSize);

	border.setSize(Settings::Instance().getMapSize());
	border.setPosition(0, 0);
	border.setOutlineThickness(5);
	border.setFillColor(sf::Color::Black);

	m_viewScore = sf::View(sf::Vector2f(0.f, 0.f), videoModeSize);
	m_viewScore.setCenter(sf::Vector2f(videoModeSize.x/2, videoModeSize.y/2));
}

void Game::initialize()
{
	m_isGameActive = true;
	m_asteroids.initialize();

	sf::Vector2f mapSize = Settings::Instance().getMapSize();
	m_ship.setPosition(mapSize.x / 2, mapSize.y / 2);
	m_ship.live();

	Score::Instance().scoreZero();
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
			sf::Vector2f windowSize(m_renderWindow->getSize().x, m_renderWindow->getSize().y);
			
			m_viewShip.setSize(windowSize);
			m_viewScore.setSize(windowSize);
			m_viewScore.setCenter(sf::Vector2f(m_renderWindow->getSize().x / 2, m_renderWindow->getSize().y / 2));
		}
	}

	render();
	update(deltaTime);

	return m_isGameActive;
}

void Game::render()
{
	m_renderWindow->clear();
	m_renderWindow->setView(m_viewShip);
	m_renderWindow->draw(border);
	m_ship.render(m_renderWindow);
	m_magazine.render(m_renderWindow);
	m_asteroids.render(m_renderWindow);
	m_renderWindow->setView(m_viewScore);
	Score::Instance().render(m_renderWindow);
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
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && !m_ship.isFire())
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !m_ship.isFire())
		m_ship.fire(m_magazine.getNextBullet());

	m_viewShip.setCenter(m_ship.getPosition());
	
	m_asteroids.intersects(m_ship, m_magazine);
	
	if (!m_ship.isAlive())
		initialize();

	if (!m_asteroids.hasAliveAsteroid())
	{
		Settings::Instance().newLevel();
		m_asteroids.initialize();
	}
}

void Game::shutdown()
{
	
}
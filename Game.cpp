#include "Game.h"
#include <cstdlib>
#include <iostream>
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

	m_view = sf::View(sf::Vector2f(0.f, 0.f), videoModeSize);

	border.setSize(Settings::Instance().getMapSize());
	border.setPosition(0, 0);
	border.setOutlineThickness(5);
	border.setFillColor(sf::Color::Black);

	view2 = sf::View(sf::Vector2f(0.f, 0.f), videoModeSize);
	view2.setCenter(sf::Vector2f(videoModeSize.x/2, videoModeSize.y/2));
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
			sf::Vector2f windowSize(m_renderWindow->getSize().x, m_renderWindow->getSize().y);
			
			m_view.setSize(windowSize);
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
	m_renderWindow->setView(view2);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
 		if (!m_ship.isFire())
			m_ship.fire(m_magazine.getNextBullet());
	
	m_view.setCenter(m_ship.getPosition());
	m_asteroids.intersects(m_ship, m_magazine);
	m_isGameActive = m_ship.isAlive();
}

void Game::shutdown()
{
	
}
#pragma once

#include <SFML/Graphics.hpp>

class Settings
{
public:
	static const unsigned int kMaxMapWidth = 5000;
	static const unsigned int kMaxMapHeight = 5000;
	static const unsigned int kMaxNumberOfAsteroids = 500;
	static const unsigned int kMaxNumberOfAmmo = 50;

	static Settings& Instance()
	{
		static Settings s;
		return s;
	}

	void setVidoeMode(unsigned int windowWidth, unsigned int windowHeight)
	{
		if (windowWidth > m_desktopMode.width)
			m_videoMode.width = m_desktopMode.width;
		else
			m_videoMode.width = windowWidth;

		if (windowHeight > m_desktopMode.height)
			m_videoMode.height = m_desktopMode.height;
		else
			m_videoMode.height = windowHeight;
	}

	sf::VideoMode getVideoMode() { return m_videoMode; }

	void setMapSize(float mapWidth, float mapHeight)
	{ 
		if (mapWidth > m_desktopMode.width)
			m_mapSize.x = m_desktopMode.width;
		else
			m_mapSize.x = mapWidth;

		if (mapHeight > m_desktopMode.height)
			m_mapSize.y = m_desktopMode.height;
		else
			m_mapSize.y = mapHeight;
	}

	sf::Vector2f getMapSize() { return m_mapSize; }
	
	void setNumberOfAsteroids(unsigned int numberOfAsteroids) { m_numberOfAsteroids = numberOfAsteroids; }
	unsigned int getNumberOfAsteroids() { return m_numberOfAsteroids; }
	
	void setNumberOfAmmo(unsigned int numberOfAmmo) { m_numberOfAmmo = numberOfAmmo; }
	unsigned int getNumberOfAmmo() { return m_numberOfAmmo; }
	
	void setAbilityProbability(float abilityProbability) { m_abilityProbability = abilityProbability; }
	float getAbilityProbability() { return m_abilityProbability; }

private:
	Settings()
	{
		m_desktopMode = sf::VideoMode::getDesktopMode();
		m_videoMode = m_desktopMode;
		m_mapSize = { 1000.0f, 1000.0f };
		m_numberOfAsteroids = 10;
		m_numberOfAmmo = 4;
		m_abilityProbability = 0.5f;
	}

	~Settings() {};
	
	Settings(Settings const &) = delete;
	Settings& operator = (Settings const &) = delete;

private:
	sf::VideoMode m_desktopMode;
	sf::VideoMode m_videoMode;

	sf::Vector2f m_mapSize;

	unsigned int m_numberOfAsteroids;
	unsigned int m_numberOfAmmo;

	float m_abilityProbability;

};
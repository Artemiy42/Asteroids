#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
public:
	virtual ~GameObject() {}
	virtual void update(float deltaTime) = 0;
	virtual void render(sf::RenderWindow* renderWindow) = 0;
};
#pragma once

#include "Command.h"
#include "SFML/Graphics/RenderWindow.hpp"

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	Command* handleInput(sf::RenderWindow renderWindow);

private:
	Command* moveUp;
	Command* rotateRight;
	Command* rotateLeft;
	Command* fire;
	Command* null;
};
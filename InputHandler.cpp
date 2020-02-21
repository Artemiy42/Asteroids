#include "InputHandler.h"

#include <SFML/Graphics.hpp>

InputHandler::InputHandler()
{
	rotateLeft = new LeftCommand();
	rotateRight = new RightCommand();
	moveUp = new UpCommand();
	fire = new FireCommand();
	null = new NullCommand();
}

InputHandler::~InputHandler()
{
	delete null;
	delete fire;
	delete moveUp;
	delete rotateRight;
	delete rotateLeft;
}

Command* InputHandler::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		return rotateLeft;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		return rotateRight;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		return moveUp;
	//if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		return fire;

	return null;
}

#pragma once

#include <SFML/Graphics.hpp>

float lengthVector(sf::Vector2f source)
{
	return sqrt((source.x * source.x) + (source.y * source.y));
}

sf::Vector2f normalize(const sf::Vector2f& source)
{
	float length = lengthVector(source);
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}

float scalarMultiplication(sf::Vector2f firstVector, sf::Vector2f secondVector)
{
	return firstVector.x * secondVector.x + firstVector.y * secondVector.y;
}
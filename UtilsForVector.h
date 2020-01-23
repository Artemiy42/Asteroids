#pragma once

#include <SFML/Graphics.hpp>

static float lengthVector(sf::Vector2f source)
{
	return sqrt((source.x * source.x) + (source.y * source.y));
}

static sf::Vector2f normalize(const sf::Vector2f& source)
{
	float length = lengthVector(source);
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}

static float scalarMultiplication(sf::Vector2f firstVector, sf::Vector2f secondVector)
{
	return firstVector.x * secondVector.x + firstVector.y * secondVector.y;
}

static sf::Vector2f vectorDirection(float angle)
{
	float angleInDegrees = angle * 3.14f / 180;
	sf::Vector2f vectorDirection = sf::Vector2f(sin(angleInDegrees), -cos(angleInDegrees));

	return vectorDirection;
}
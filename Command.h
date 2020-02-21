#pragma once

#include "Ship.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute(Ship* ship) = 0;
};

class UpCommand : public Command
{
public:
	virtual void execute(Ship* ship);
};

class RightCommand : public Command
{
public:
	virtual void execute(Ship* ship);
};

class LeftCommand : public Command
{
public:
	virtual void execute(Ship* ship);
};

class FireCommand : public Command
{
public:
	virtual void execute(Ship* ship);
};

class NullCommand : public Command
{
public:
	virtual void execute(Ship* ship) {}
};

#include "Command.h"

void UpCommand::execute(Ship* ship)
{
	ship->addForce();
}

void RightCommand::execute(Ship* ship)
{
	ship->rotate(ship->kAngleRotation);
}

void LeftCommand::execute(Ship* ship)
{
	ship->rotate(-ship->kAngleRotation);
}

void FireCommand::execute(Ship* ship)
{
	if (!ship->isFire())
		ship->fire();
}

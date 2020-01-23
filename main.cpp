#include "Game.h"
#include "Assets.h"

int main()
{
	Assets::Instance().load();

	Game game;

	game.setupSystem();
	game.initialize();

	while (game.loop());

	game.shutdown();

	return 0;
}
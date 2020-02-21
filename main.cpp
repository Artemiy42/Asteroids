#include <iostream>
#include <string>
#include <vector>

#include "Game.h"
#include "Assets.h"
#include "Settings.h"

int main(int argc, char* argv[])
{
    Assets::Instance().load();

    Game game;

    game.setupSystem();
    game.initialize();

    while (game.loop());

    game.shutdown();

    return 0;
}
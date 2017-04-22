#include <iostream>
#include "Game.h"

int main() {
    Game *game = new Game("TEST", 1000, 1000, (Uint32) 0);

    game->init();
    game->run();
    return 0;
}
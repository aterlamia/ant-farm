#include <iostream>
#include "Game.h"

int main() {
    Game *game = new Game("ANTFARM", 1024, 1024, (Uint32) 0);

    game->init();
    game->run();
    return 0;
}
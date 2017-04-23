#include <iostream>
#include "MyGame.h"

int main() {
  MyGame *game = new MyGame("ANTFARM", 1024, 1024, (Uint32) 0);

  game->init();
  game->run();
  return 0;
}
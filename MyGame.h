//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef TESTGAME_GAME_H
#define TESTGAME_GAME_H


#include <Game.h>
#include <utils/fps.h>
#include "Layer/LayerInterface.h"
#include "Jobs/JobManager.h"
#include "Layer/LayerManager.h"

class MyGame : public Ember::Game {
public:
  MyGame(
      const char *m_title,
      int m_windowHeight,
      int m_windowWidth,
      Uint32 flags
  );

  bool init();

protected:
  void registerAssetLoaders(Ember::EventBus *pBus) override;

  void loadScene();
  void postRenderCreate(SDL_Renderer *pRenderer) override;
  void render() override;
  void update() override;
  Fps *fps;
};


#endif //TESTGAME_GAME_H
    
//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef TESTGAME_GAME_H
#define TESTGAME_GAME_H


#include <Game.h>
#include "GameObject/Map.h"
#include "Layer/LayerInterface.h"
#include "Jobs/JobManager.h"

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

  void render() override;
  void update() override;

  std::vector<LayerInterface *> m_layers;

  JobManager *m_jobManager;
};


#endif //TESTGAME_GAME_H
    
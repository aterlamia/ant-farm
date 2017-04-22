//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef TESTGAME_GAME_H
#define TESTGAME_GAME_H


#include <Game.h>

class Game : public Ember::Game {
public:
    Game(const char *m_title, int m_windowHeight, int m_windowWidth, Uint32 flags);

protected:
    void registerAssetLoaders(Ember::EventBus *pBus) override;

    void loadScene();
};


#endif //TESTGAME_GAME_H
    
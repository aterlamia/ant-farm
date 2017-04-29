//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_GAME_H
#define EMBERENGINE_GAME_H

#include "Events/EventBus.h"
#include "Assets/AssetLoaderInterface.h"
#include "System/InputHandler.h"
#include "State/GameState.h"
#include "Objects/GameObject.h"
#include <SDL.h>

namespace Ember {
  class Game {
  protected:
    const int FPS = 60;
    const int DELAY_TIME = 1000.0f / FPS;
    const char *m_title;

    int m_windowHeight;
    int m_windowWidth;

    Uint32 flags;

    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

    EventBus *m_bus;

    std::vector<AssetLoaderInterface *> m_assetLoaders;
    std::vector<GameObject *> m_gameobjects;

  public:
    Game(
        const char *m_title,
        int m_windowHeight,
        int m_windowWidth,
        Uint32 flags
    );

    virtual bool init();

    bool run();

    virtual ~Game();

  protected:

    void registerListeners(EventBus *bus);

    void handleGame();

    void handleInput();

    virtual void update();

    void internalRender();

    virtual void render() = 0;

    virtual void registerAssetLoaders(EventBus *pBus);

    GameState *m_gameState;

    InputHandler *m_inputHandler;

    void loadAssets();

    virtual void loadScene() = 0;
    virtual void postRenderCreate(SDL_Renderer *pRenderer);
  };
};


#endif //EMBERENGINE_GAME_H

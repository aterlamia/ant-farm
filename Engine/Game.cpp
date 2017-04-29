//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <iostream>
#include "Game.h"
#include "System/Logger.h"
#include "Assets/TextureManager.h"

namespace Ember {
  bool Game::init() {
    m_gameState = new GameState();
    m_bus = new EventBus();


    m_bus->fire(new LogEVent("Initializing sdl", LOG_CANAL::SDL, LOG_TYPE::INFO_TYPE));
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
      m_window = SDL_CreateWindow(
          m_title, 0, 0, m_windowHeight, m_windowWidth, flags
      );

      if (m_window != 0) {
        m_renderer = SDL_CreateRenderer(
            m_window, -1, 0
        );
        postRenderCreate(m_renderer);
      }


      m_bus->fire(
          new LogEVent("Initializing Asset loaders", LOG_CANAL::ASSETS, LOG_TYPE::INFO_TYPE));

      m_inputHandler = new InputHandler(m_bus);

      registerListeners(m_bus);
      registerAssetLoaders(m_bus);

      loadAssets();

      loadScene();
      m_bus->fire(new LogEVent("Initializing sdl success", LOG_CANAL::SDL, LOG_TYPE::INFO_TYPE));
      // Everything succesfull then allow the loop to start.
      m_gameState->setRunning(true);
    } else {
      m_bus->fire(new LogEVent("Initializing sdl", LOG_CANAL::SDL, LOG_TYPE::ERROR_TYPE));
      return false;
    }
    return true;

  }

  void Game::registerListeners(EventBus *bus) {
    Logger *logger = new Logger();
    bus->subscribe(logger);

    bus->subscribe(m_gameState);
  }

  Game::Game(
      const char *m_title,
      int m_windowHeight,
      int m_windowWidth,
      Uint32 flags
  )
      : m_title(m_title)
        , m_windowHeight(m_windowHeight)
        , m_windowWidth(m_windowWidth)
        , flags(flags) {}

  bool Game::run() {
    Uint32 frameStart, frameTime;

    while (m_gameState->isRunning()) {
      handleGame();

      frameStart = SDL_GetTicks();
      frameTime = SDL_GetTicks() - frameStart;

      /** Makes sure the game  runs in a steady pase */
      if (frameTime < DELAY_TIME) {
        /**
         * @todo This is the simple way of doing this but it is more imorrant that the graphics update in a steady pace
         * so we dont have "lag" so we need to enhance this to make sure calculations and other logic kan be skipped
         * but display logic runs the same speed always.
         */

        SDL_Delay((int) (DELAY_TIME - frameTime));
      }

    }
    return false;
  }

  void Game::handleGame() {
    handleInput();
    update();
    internalRender();
  }

  void Game::handleInput() {
    m_inputHandler->handleInput();

  }

  void Game::update() {
  }

  void Game::internalRender() {
    SDL_SetRenderDrawColor(
        m_renderer,
        99,
        99,
        99,
        255);

    // clear the window to black
    SDL_RenderClear(m_renderer);


    for (std::vector<GameObject *>::size_type i = 0; i != m_gameobjects.size(); i++) {
      m_gameobjects[i]->render();
    }

    render();

    // show the window
    SDL_RenderPresent(m_renderer);
  }

  void Game::registerAssetLoaders(EventBus *pBus) {
  }

  void Game::loadAssets() {
    for (std::vector<AssetLoaderInterface *>::size_type i = 0; i != m_assetLoaders.size(); i++) {
      m_bus->fire(new LogEVent("Loading assets", LOG_CANAL::ASSETS, LOG_TYPE::INFO_TYPE));
      m_assetLoaders[i]->loadAssets();
    }
  }

  Game::~Game() {


  }

  void Game::postRenderCreate(SDL_Renderer *pRenderer) {

  }

}
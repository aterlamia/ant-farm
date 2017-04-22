//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <Components/TextureComponent.h>
#include "Game.h"
#include "Assets/StaticAssetLoader.h"
#include "Layer/MapLayer.h"
#include "Layer/CharacterLayer.h"

Game::Game(const char *m_title, int m_windowHeight, int m_windowWidth, Uint32 flags)
    : Ember::Game(m_title, m_windowHeight, m_windowWidth, flags) {
}

void Game::registerAssetLoaders(Ember::EventBus *pBus) {
  m_assetLoaders.push_back(new StaticAssetLoader(m_bus));
}

bool Game::init() {
  if (Ember::Game::init()) {
    m_jobManager = new JobManager();

    m_bus->subscribe(m_jobManager);

    return true;
  }
  return false;
}

void Game::loadScene() {
  Ember::TextureComponent *component = new Ember::TextureComponent(
      Ember::COMPONENT_VISUAL,
      "LogoSmall",
      Ember::Position2d(m_windowHeight - 100, m_windowHeight - 90),
      Ember::Dimension2d(100, 90),
      m_bus
  );

  Ember::GameObject *object = new Ember::GameObject("Logo");
  object->addComponent(component);

  m_gameobjects.push_back(object);


  Map *map = new Map(m_bus, 16, 16);
  map->init();

  MapLayer *mapLayer = new MapLayer(map);
  CharacterLayer *characterLayer = new CharacterLayer(m_bus);

  m_layers.push_back(mapLayer);
  m_layers.push_back(characterLayer);


}

void Game::render() {
  for (std::vector<LayerInterface *>::size_type i = 0; i != m_layers.size(); i++) {
    m_layers[i]->render();
  }
}
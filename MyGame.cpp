//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "MyGame.h"
#include "Assets/StaticAssetLoader.h"
#include "Layer/CharacterLayer.h"
#include "System/ServiceContainer.h"

MyGame::MyGame(
    const char *m_title,
    int m_windowHeight,
    int m_windowWidth,
    Uint32 flags
)
    : Ember::Game(m_title, m_windowHeight, m_windowWidth, flags) {
}

void MyGame::registerAssetLoaders(Ember::EventBus *pBus) {
  m_assetLoaders.push_back(new StaticAssetLoader(m_bus));
}

bool MyGame::init() {

  LayerManager *layerManager = new LayerManager();
  ServiceContainer::GetInstance()->Provide(new SceneManager(layerManager));

  if (Ember::Game::init()) {
    JobManager *jobManager = new JobManager();
    m_bus->subscribe(jobManager);
    ServiceContainer::GetInstance()->Provide(jobManager);
    return true;
  }
  return false;
}

void MyGame::loadScene() {
  Ember::TextureComponent *component = new Ember::TextureComponent(
      Ember::COMPONENT_VISUAL,
      "LogoSmall",
      Ember::Dimension2d(100, 90),
      m_bus
  );

  Ember::GameObject *object = new Ember::GameObject(
      "Logo",
      Ember::Position2d(m_windowHeight - 100, m_windowHeight - 90)
  );
  object->addComponent(component);

  m_gameobjects.push_back(object);

  Map *map = new Map(m_bus, 16, 16);
  map->init();

  MapLayer *mapLayer = new MapLayer(map);
  CharacterLayer *characterLayer = new CharacterLayer(m_bus);

  LayerManager *manager = ServiceContainer::GetInstance()->getSceneManager().getLayerManager();
  manager->addLayer(LayerManager::LAYER_MAP, mapLayer);
  manager->addLayer(LayerManager::LAYER_CHARCTERS, characterLayer);
}

void MyGame::render() {
  LayerManager *manager = ServiceContainer::GetInstance()->getSceneManager().getLayerManager();

  for (auto it = manager->getLayers().begin(); it != manager->getLayers().end(); ++it) {
    // Eww, make a NUlL layer or something
    if (it->second != nullptr) {
      it->second->render();
    }
  }
}

void MyGame::update() {
  Ember::Game::update();
  LayerManager *manager = ServiceContainer::GetInstance()->getSceneManager().getLayerManager();

  for (auto it = manager->getLayers().begin(); it != manager->getLayers().end(); ++it) {
    // Eww, make a NUlL layer or something
    if (it->second != nullptr) {
      it->second->update();
    }
  }
}

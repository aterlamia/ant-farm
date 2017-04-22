//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <Components/TextureComponent.h>
#include "Game.h"
#include "Assets/StaticAssetLoader.h"

Game::Game(const char *m_title, int m_windowHeight, int m_windowWidth, Uint32 flags)
        : Ember::Game(m_title, m_windowHeight, m_windowWidth, flags) {
}

void Game::registerAssetLoaders(Ember::EventBus *pBus) {
    m_assetLoaders.push_back(new StaticAssetLoader(m_bus));
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


    m_map = new Map(m_bus, 16, 16);
    m_map->init();

}

void Game::render() {
    m_map->render();
}
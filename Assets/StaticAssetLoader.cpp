//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "StaticAssetLoader.h"
#include <Events/LoadTextureEvent.h>

void StaticAssetLoader::loadAssets() {
    m_bus->fire(new Ember::LoadTextureEvent("Logo", "assets/logo.png"));
    m_bus->fire(new Ember::LoadTextureEvent("LogoSmall", "assets/logo-small.png"));
    m_bus->fire(new Ember::LoadTextureEvent("LogoGray", "assets/logo-gray.png"));
}

StaticAssetLoader::StaticAssetLoader(Ember::EventBus *bus)
        : m_bus(bus) {}

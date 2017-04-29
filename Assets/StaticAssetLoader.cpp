//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "StaticAssetLoader.h"
#include "../System/ServiceContainer.h"

void StaticAssetLoader::loadAssets() {
  ServiceContainer::GetInstance()->getTextureManager().load("assets/logo.png", "Logo");
  ServiceContainer::GetInstance()->getTextureManager().load("assets/logo-small.png", "LogoSmall");
  ServiceContainer::GetInstance()->getTextureManager().load("assets/logo-gray.png", "LogoGray");
  ServiceContainer::GetInstance()->getTextureManager().load("assets/groundtile.png", "Tile");
  ServiceContainer::GetInstance()->getTextureManager().load("assets/characters.png", "Characters");
}

StaticAssetLoader::StaticAssetLoader(Ember::EventBus *bus)
    : m_bus(bus) {}

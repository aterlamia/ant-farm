//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <Components/TiledTextureComponent.h>
#include "CharacterLayer.h"
#include "../Components/Ant.h"

void CharacterLayer::render() {
  for (std::vector<Ember::GameObject *>::size_type i = 0; i != characters.size(); i++) {
    characters[i]->render();
  }
}

CharacterLayer::CharacterLayer(Ember::EventBus *m_bus)
    : m_bus(m_bus) {

  Ember::GameObject *worker = new Ember::GameObject("Character", Ember::Position2d(8 * 64, 8 * 64));
  worker->addComponent(
      new Ant(
          Ember::COMPONENT_VISUAL,
          "Characters",
          Ember::Dimension2d(64, 64),
          Ember::Frame(1, 2),
          m_bus
      )
  );

  characters.push_back(worker);
}

void CharacterLayer::update() {
  for (std::vector<Ember::GameObject *>::size_type i = 0; i != characters.size(); i++) {
    characters[i]->update();
  }
}

//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "Ant.h"

Ant::Ant(
    Ember::EMBER_COMPONENT m_componentType,
    const std::string &m_texture,
    const Ember::Position2d &m_position,
    const Ember::Dimension2d &m_dimension,
    const Ember::Frame &m_frame,
    Ember::EventBus *m_bus
)
    : TiledTextureComponent(m_componentType, m_texture, m_position, m_dimension, m_frame, m_bus) {}

void Ant::setTileType(Ant::CHARACTER_TYPE m_characterType) {
  Ant::m_characterType = m_characterType;
}

void Ant::setHealth(int m_health) {
  Ant::m_health = m_health;
}

void Ant::setMineable(bool m_mineable) {
  Ant::m_mineable = m_mineable;
}

void Ant::handleEvent(Ember::EventInterface &event) {

}

void Ant::handleGraphical() {
  Ember::TiledTextureComponent::handleGraphical();
}

void Ant::handleUpdates() {
  // eat
  if (m_hunger < 20) {
    return;
  }

  // heal
  if (m_health < 20) {
    return;
  }

  // sleep
  if (m_energy < 20) {
    return;
  }

//  if (m_job == nullptr) {
//    m_bus->fire()
//  }
}

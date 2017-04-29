//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "MineEvent.h"

std::string MineEvent::getType() {
  return "mine_event";
}

Ember::EventMessage MineEvent::getMessage() {
  Ember::EventMessage message = Ember::EventMessage();

  message.object = m_tile->getLinkedObject();

  return message;
}

MineEvent::MineEvent(
    Tile *m_tile,
    const Ember::Vector2D &m_position
) : m_position(m_position)
    , m_tile(m_tile) {}



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
  return message;
}

MineEvent::MineEvent(Tile *m_tile)
    : m_tile(m_tile) {}


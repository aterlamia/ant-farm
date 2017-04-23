//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "TileObject.h"

TileObject::TileObject(
      const std::string &m_name,
      Ember::Position2d m_position
  ) : GameObject(m_name, Ember::Position2d(0, 0))
      , m_position(m_position) {}

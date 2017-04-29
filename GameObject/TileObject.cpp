//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "TileObject.h"

TileObject::TileObject(
    const std::string &m_name,
    Ember::Vector2D m_position
) : GameObject(m_name, m_position) {}

bool TileObject::isMinable() const {
  return minable;
}

void TileObject::setMinable(bool minable) {
  TileObject::minable = minable;
}

bool TileObject::isPassable() const {
  return passable;
}

void TileObject::setPassable(bool passable) {
  TileObject::passable = passable;
}

int TileObject::getHealth() const {
  return health;
}

void TileObject::setHealth(int health) {
  TileObject::health = health;
}

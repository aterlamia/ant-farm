//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "Tile.h"
#include "../Events/MineEvent.h"
#include <Events/LogEVent.h>

Tile::Tile(
    Ember::EMBER_COMPONENT m_componentType,
    const std::string &m_texture,
    const Ember::Position2d &m_position,
    const Ember::Dimension2d &m_dimension,
    const Ember::Frame &m_frame, Ember::EventBus *m_bus
)
    : TiledTextureComponent(m_componentType, m_texture, m_position, m_dimension, m_frame, m_bus) {
  m_bus->subscribe(this);
}

void Tile::setTileType(Tile::TILE_TYPE m_tileType) {
  Tile::m_tileType = m_tileType;
}

void Tile::setHealth(int m_health) {
  Tile::m_health = m_health;
}

void Tile::setMineable(bool m_mineable) {
  Tile::m_mineable = m_mineable;
}

void Tile::handleEvent(Ember::EventInterface &event) {

  if (event.getType() == "mouse_event") {
    Ember::EventMessage message = event.getMessage();

    if (
        message.mousePosition.Y >= m_position.Y
        && message.mousePosition.Y < m_position.Y + m_dimension.height
        && message.mousePosition.X >= m_position.X
        && message.mousePosition.X < m_position.X + m_dimension.width
        ) {
      m_frame = Ember::Frame(1, 5);
      m_bus->fire(
          new MineEvent(
              this
          )
      );
    }

  }
}
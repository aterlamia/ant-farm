//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "Tile.h"
#include "../Events/MineEvent.h"
#include "../System/ServiceContainer.h"
#include "../Jobs/MineJob.h"
#include <Events/LogEVent.h>

Tile::Tile(
    Ember::EMBER_COMPONENT m_componentType,
    const std::string &m_texture,
    const Ember::Position2d &m_position,
    const Ember::Dimension2d &m_dimension,
    const Ember::Frame &m_frame,
    Ember::EventBus *m_bus
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
    handleMouseEvent(event);
  } else if (event.getType() == "mine_event") {
    handleMineEvent(event);
  }
}

void Tile::handleMouseEvent(Ember::EventInterface &event) {
  Ember::EventMessage message = event.getMessage();

  if (
      message.mousePosition.Y >= m_position.Y
      && message.mousePosition.Y < m_position.Y + m_dimension.height
      && message.mousePosition.X >= m_position.X
      && message.mousePosition.X < m_position.X + m_dimension.width
      ) {

//    m_bus->fire(
//        new MineEvent(
//            this,
//            Ember::Position2d(m_position.X / m_dimension.width, m_position.Y / m_dimension.height)
//        )
//    );

    if (m_mineable ) {

      // Temp line to visualize
      m_frame = Ember::Frame(1, 5);

      ServiceContainer::GetInstance()->getJobManager().addJob(
          new MineJob(Ember::Position2d(m_position.X / m_dimension.width, m_position.Y / m_dimension.height))
      );
    }
  }
}

void Tile::handleMineEvent(Ember::EventInterface &event) {

}

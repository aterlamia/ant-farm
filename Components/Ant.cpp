//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "Ant.h"
#include "../System/ServiceContainer.h"
#include "../Events/EventMessage.h"

Ant::Ant(
    Ember::EMBER_COMPONENT m_componentType,
    const std::string &m_texture,
    const Ember::Dimension2d &m_dimension,
    const Ember::Frame &m_frame,
    Ember::EventBus *m_bus
)
    : TiledTextureComponent(m_componentType, m_texture, m_dimension, m_frame, m_bus) {}

void Ant::setTileType(Ant::CHARACTER_TYPE m_characterType) {
  Ant::m_characterType = m_characterType;
}

void Ant::setHealth(int m_health) {
  Ant::m_health = m_health;
}

void Ant::handleEvent(Ember::EventInterface &event) {
  if (event.getType() != "input_event") {
    return;
  }
  Ember::EventMessage message = event.getMessage();

  Ember::Vector2D position = {m_object->getPosition().X, m_object->getPosition().Y};

  Ember::Vector2D add = {0, 0};

  TileObject *tile;

//    m_object->getPosition().Add(movement);
  if (message.eventType == Ember::KEYBOARD_EVENT_DOWN && message.key == SDL_SCANCODE_W) {
//    Ember::Vector2D movement = {-2.5, 0};
//    m_object->getPosition().Add(movement);
  } else if (message.eventType == Ember::KEYBOARD_EVENT_DOWN && message.key == SDL_SCANCODE_A) {
    add.Y = 0;
    add.X = -24 ;
    position.Add(add);

    tile = ServiceContainer::GetInstance()->getSceneManager().getLayerManager()->getMapLayer()->getTileObjectByPosition(
        {std::round(position.X / 64), std::round(position.Y / 64)});

    if (tile->isPassable() == false) {
      return;
    }

    Ember::Vector2D movement = {-4, 0};
    m_object->getPosition().Add(movement);
  } else if (message.eventType == Ember::KEYBOARD_EVENT_DOWN && message.key == SDL_SCANCODE_D) {
    add.Y = 0;
    add.X = 24;
    position.Add(add);

    tile = ServiceContainer::GetInstance()->getSceneManager().getLayerManager()->getMapLayer()->getTileObjectByPosition(
        {std::round(position.X / 64), std::round(position.Y / 64)});

    if (tile->isPassable() == false) {
      return;
    }

    Ember::Vector2D movement = {4, 0};
    m_object->getPosition().Add(movement);
  } else if (message.eventType == Ember::KEYBOARD_EVENT_DOWN && message.key == SDL_SCANCODE_S) {
//    Ember::Vector2D movement = {-2.5, 0};
//    m_object->getPosition().Add(movement);
  }
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

  Ember::Vector2D position = {m_object->getPosition().X, m_object->getPosition().Y};

  Ember::Vector2D add = {0, 0};
  TileObject *tile;

  add.Y = 32;
  add.X = 20;
  position.Add(add);

  tile = ServiceContainer::GetInstance()->getSceneManager().getLayerManager()->getMapLayer()->getTileObjectByPosition(
      {std::round(position.X / 64), std::round(position.Y / 64)});

  if (tile->isPassable() == true) {
    Ember::Vector2D movement = {0, 4};
    m_object->getPosition().Add(movement);
  }

//  if (m_job == nullptr) {
//    // Get Job.
//    m_job = ServiceContainer::GetInstance()->getJobManager().assingJob(this);
//
//    if (m_job != nullptr) {
//      MapLayer *layer = ServiceContainer::getSceneManager().getLayerManager()->getMapLayer();
//      Ember::Vector2D pos = {m_object->getPosition().X / 64, m_object->getPosition().Y / 64};
//      layer->getPath(pos, m_job->getPosition());
//
//    }
//  } else {
//  }


}

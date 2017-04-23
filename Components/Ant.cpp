//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "Ant.h"
#include "../System/ServiceContainer.h"

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

  if (m_job == nullptr) {
    // Get Job.
    std::cout << "Getting job \n";
    m_job = ServiceContainer::GetInstance()->getJobManager().assingJob(this);

    if (m_job != nullptr) {


      MapLayer *layer = ServiceContainer::getSceneManager().getLayerManager()->getMapLayer();

      std::cout << m_job->getPosition().Y << "\n";
      std::cout << m_job->getPosition().X << "\n";
    }
  } else {
  }


}

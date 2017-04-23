//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_ANT_H
#define ANTFARM_ANT_H


#include <Components/TiledTextureComponent.h>
#include "../Jobs/JobInterface.h"

class Ant : public Ember::TiledTextureComponent, public Ember::EventListenerInterface {
public:
  Ant(
      Ember::EMBER_COMPONENT m_componentType,
      const std::string &m_texture,
      const Ember::Dimension2d &m_dimension,
      const Ember::Frame &m_frame,
      Ember::EventBus *m_bus
  );

  void handleEvent(Ember::EventInterface &event) override;

public:
  enum CHARACTER_TYPE {
    CHARACTER_NONE,
    CHARACTER_QUEEN,
    CHARACTER_WORKER,
  };

  void setTileType(CHARACTER_TYPE m_characterType);

  void setHealth(int m_health);

  void handleGraphical() override;
  void handleUpdates() override;

protected:
  CHARACTER_TYPE m_characterType = CHARACTER_NONE;
  int m_health = 100;
  int m_hunger = 100;
  int m_energy = 100;
  JobInterface *m_job = nullptr;
};


#endif //ANTFARM_ANT_H

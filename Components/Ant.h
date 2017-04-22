//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_ANT_H
#define ANTFARM_ANT_H


#include <Components/TiledTextureComponent.h>

class Ant : public Ember::TiledTextureComponent, public Ember::EventListenerInterface {
public:
  Ant(
      Ember::EMBER_COMPONENT m_componentType,
      const std::string &m_texture,
      const Ember::Position2d &m_position,
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

  void setMineable(bool m_mineable);

  void handleGraphical() override;

protected:
  CHARACTER_TYPE m_characterType = CHARACTER_NONE;
  int m_health = 100;
  bool m_mineable = true;
};


#endif //ANTFARM_ANT_H

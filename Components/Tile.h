//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_TILE_H
#define ANTFARM_TILE_H


#include <Components/ComponentInterface.h>
#include <Components/TiledTextureComponent.h>


class Tile : public Ember::TiledTextureComponent {
public:
  enum TILE_TYPE {
    TILE_NONE,
    TILE_SOIL,
  };

public:
  Tile(
      Ember::EMBER_COMPONENT m_componentType,
      const std::string &m_texture,
      const Ember::Dimension2d &m_dimension,
      const Ember::Frame &m_frame,
      Ember::EventBus *m_bus
  );

  void setTileType(TILE_TYPE m_tileType);
  void setHealth(int m_health);
  void setMineable(bool m_mineable);

protected:
  void handleMineEvent(Ember::EventInterface &event);
  void handleMouseEvent(Ember::EventInterface &event);

protected:
  TILE_TYPE m_tileType = TILE_NONE;
  int m_health = 100;
  bool m_mineable = true;

};

#endif //ANTFARM_TILE_H

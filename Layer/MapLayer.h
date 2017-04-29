//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_MAPLAYER_H
#define ANTFARM_MAPLAYER_H


#include <Events/EventBus.h>
#include "LayerInterface.h"
#include "../GameObject/TileObject.h"

class MapLayer : public LayerInterface {

public:
  void update() override;

  void render() override;
  void init();

public:
  MapLayer(
      Ember::EventBus *m_bus,
      int m_tilesRow,
      int m_tilesColumn
  );

  TileObject * getTileObjectByPosition(Ember::Vector2D);

  std::vector<TileObject *> getPath(
      Ember::Vector2D begin,
      Ember::Vector2D end
  );


protected:
  std::vector<std::vector<TileObject *>> m_map;
  Ember::EventBus *m_bus;
  int m_tilesRow;
  int m_tilesColumn;
  std::vector<TileObject *> getTilePath(
      Ember::Vector2D begin,
      Ember::Vector2D end,
      Ember::Vector2D cameFrom,
      std::vector<TileObject *> route
  );
  bool arrived(
      Ember::Vector2D next,
      Ember::Vector2D end
  );
};

#endif //ANTFARM_MAPLAYER_H

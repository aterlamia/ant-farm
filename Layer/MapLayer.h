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

  TileObject * getTileObjectByPosition(Ember::Position2d);

  std::vector<TileObject *> getPath(
      Ember::Position2d begin,
      Ember::Position2d end
  );


protected:
  std::vector<std::vector<TileObject *>> m_map;
  Ember::EventBus *m_bus;
  int m_tilesRow;
  int m_tilesColumn;
  std::vector<TileObject *> getTilePath(
      Ember::Position2d begin,
      Ember::Position2d end,
      Ember::Position2d cameFrom,
      std::vector<TileObject *> route
  );
  bool arrived(
      Ember::Position2d next,
      Ember::Position2d end
  );
};

#endif //ANTFARM_MAPLAYER_H

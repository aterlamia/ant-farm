//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_MAP_H
#define ANTFARM_MAP_H


#include <Objects/GameObject.h>
#include <Events/EventBus.h>
#include "../Components/Tile.h"

class Map {
public:
  void init();


  void render();

private:
public:
  Map(Ember::EventBus *m_bus, int m_tilesRow, int m_tilesColumn);

private:
  std::vector<std::vector<Ember::GameObject *>> m_map;
  Ember::EventBus *m_bus;
  int m_tilesRow;
  int m_tilesColumn;
};


#endif //ANTFARM_MAP_H

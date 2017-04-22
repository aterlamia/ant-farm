//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_MAPLAYER_H
#define ANTFARM_MAPLAYER_H


#include "LayerInterface.h"
#include "../GameObject/Map.h"

class MapLayer : public LayerInterface {

public:
  MapLayer(Map *m_map);

  void render() override;


protected:
  Map *m_map;
};


#endif //ANTFARM_MAPLAYER_H

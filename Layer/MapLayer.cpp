//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "MapLayer.h"


/**
 * Constructor.
 * @param m_map
 */
MapLayer::MapLayer(Map *m_map)
    : m_map(m_map) {}


void MapLayer::render() {
  m_map->render();
}

void MapLayer::update() {

}

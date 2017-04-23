//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "SceneManager.h"

SceneManager::SceneManager(LayerManager *m_layerManager) : m_layerManager(m_layerManager) {}

LayerManager *SceneManager::getLayerManager() const {
  return m_layerManager;
}

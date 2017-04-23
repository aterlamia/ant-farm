//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_LAYERMANAGER_H
#define ANTFARM_LAYERMANAGER_H

#include <vector>
#include <map>
#include "LayerInterface.h"
#include "MapLayer.h"

class LayerManager {
public:
  typedef enum {
    LAYER_BACKGROUND,
    LAYER_MAP,
    LAYER_CHARCTERS,
    LAYER_OVERLAY,
    LAYER_UI
  } LayerTypes;
private:
  std::map<LayerManager::LayerTypes, LayerInterface *> m_layers;

public:

  LayerManager() {
    m_layers[LAYER_BACKGROUND] = nullptr;
    m_layers[LAYER_MAP] = nullptr;
    m_layers[LAYER_CHARCTERS] = nullptr;
    m_layers[LAYER_OVERLAY] = nullptr;
    m_layers[LAYER_UI] = nullptr;
  }

  void render() {
    if (m_layers[LAYER_BACKGROUND] != nullptr) {
      m_layers[LAYER_BACKGROUND]->render();
    }

    if (m_layers[LAYER_MAP] != nullptr) {
      m_layers[LAYER_MAP]->render();
    }

    if (m_layers[LAYER_CHARCTERS] != nullptr) {
      m_layers[LAYER_CHARCTERS]->render();
    }

    if (m_layers[LAYER_OVERLAY] != nullptr) {
      m_layers[LAYER_OVERLAY]->render();
    }

    if (m_layers[LAYER_UI] != nullptr) {
      m_layers[LAYER_UI]->render();
    }
  }

  void addLayer(
      LayerTypes type,
      LayerInterface *layer
  ) {
    m_layers[type] = layer;
  }

  LayerInterface *getLayer(LayerTypes type) {
    return m_layers[type];
  }

  MapLayer *getMapLayer() {
    return static_cast<MapLayer *>(m_layers[LAYER_MAP]);
  }
};


#endif //ANTFARM_LAYERMANAGER_H

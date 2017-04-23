//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_SCENEMANAGER_H
#define ANTFARM_SCENEMANAGER_H


#include "../Layer/LayerManager.h"

class SceneManager {
public:
  SceneManager(LayerManager *m_layerManager);
  LayerManager *getLayerManager() const;
protected:
  LayerManager * m_layerManager;
};

#endif //ANTFARM_SCENEMANAGER_H

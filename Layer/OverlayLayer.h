//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_OVERLAYLAYER_H
#define ANTFARM_OVERLAYLAYER_H


#include <vector>
#include <Objects/GameObject.h>

class OverlayLayer {
protected:
  std::vector<std::vector<Ember::GameObject *>> m_map;
};


#endif //ANTFARM_OVERLAYLAYER_H

//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_CHARACTERLAYER_H
#define ANTFARM_CHARACTERLAYER_H


#include "LayerInterface.h"
#include <Objects/GameObject.h>

class CharacterLayer : public LayerInterface {
public:
  void render() override;

  CharacterLayer(Ember::EventBus *m_bus);

private:
  std::vector<Ember::GameObject *> characters;
  Ember::EventBus *m_bus;
};


#endif //ANTFARM_CHARACTERLAYER_H

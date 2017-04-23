//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_GAMEOBJECT_H
#define EMBERENGINE_GAMEOBJECT_H


#include <vector>
#include <string>
#include "../Components/ComponentInterface.h"

namespace Ember {
  class ComponentInterface;

  class GameObject {
  private:
    std::vector<ComponentInterface *> m_components;
    std::string m_name;
  public:
    GameObject(const std::string &m_name);

    void addComponent(ComponentInterface *component);

    void render();

    void update();
  };
};


#endif //EMBERENGINE_GAMEOBJECT_H

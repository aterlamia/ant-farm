//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_GAMEOBJECT_H
#define EMBERENGINE_GAMEOBJECT_H


#include <vector>
#include <string>
#include <ValueObjects/Vector2D.h>
#include "../Components/ComponentInterface.h"

namespace Ember {
  class ComponentInterface;

  class GameObject {
  private:
    std::vector<ComponentInterface *> m_components;
    std::string m_name;
  protected:
    Vector2D m_position;
  public:
    GameObject(
        const std::string &m_name,
        Vector2D m_position
    );
    void addComponent(ComponentInterface *component);

    void render();

    void update();

    Vector2D &getPosition();
    void setPosition(Vector2D &m_position);
  };
};


#endif //EMBERENGINE_GAMEOBJECT_H

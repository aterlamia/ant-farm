//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_GAMEOBJECT_H
#define EMBERENGINE_GAMEOBJECT_H


#include <vector>
#include <string>
#include <ValueObjects/Position2d.h>
#include "../Components/ComponentInterface.h"

namespace Ember {
  class ComponentInterface;

  class GameObject {
  private:
    std::vector<ComponentInterface *> m_components;
    std::string m_name;
    Position2d m_position;
  public:
    GameObject(
          const std::string &m_name,
          Position2d m_position
      );

    void addComponent(ComponentInterface *component);

    void render();

    void update();
    const Position2d &getPosition() const;
  };
};


#endif //EMBERENGINE_GAMEOBJECT_H

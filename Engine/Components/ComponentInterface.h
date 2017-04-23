//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_COMPONENTINTERFACE_H
#define EMBERENGINE_COMPONENTINTERFACE_H

#include "../Objects/GameObject.h"

namespace Ember {
  class GameObject;

  typedef enum {
    COMPONENT_INPUT,
    COMPONENT_VISUAL,
    COMPONENT_UPDATE,
    COMPONENT_OTHER
  } EMBER_COMPONENT;

  class ComponentInterface {
  protected:
    EMBER_COMPONENT m_componentType;
    GameObject *m_object;
  public:
    ComponentInterface(EMBER_COMPONENT m_componentType)
        : m_componentType(m_componentType) {}

    virtual void handleGraphical() = 0;

    virtual void handleInput()= 0;

    virtual void handleUpdates()= 0;

    void linkObject(GameObject *m_object) {
      ComponentInterface::m_object = m_object;
    }

    GameObject *getLinkedObject() {
      return ComponentInterface::m_object;
    };
  };
};

#endif //EMBERENGINE_COMPONENTINTERFACE_H

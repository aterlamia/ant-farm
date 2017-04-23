//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "GameObject.h"

namespace Ember {
  void GameObject::addComponent(ComponentInterface *component) {
    component->linkObject(this);
    m_components.push_back(component);
  }

  GameObject::GameObject(const std::string &m_name)
      : m_name(m_name) {}

  void GameObject::render() {
    for (std::vector<ComponentInterface *>::size_type i = 0; i != m_components.size(); i++) {
      m_components[i]->handleGraphical();
    }
  }
};

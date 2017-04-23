//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "TextureComponent.h"
#include "../Events/RenderEvent.h"

namespace Ember {

  void TextureComponent::handleGraphical() {
    m_bus->fire(new RenderEvent(m_object->getPosition(), m_dimension, m_texture));
  }

  void TextureComponent::handleInput() {
  }

  void TextureComponent::handleUpdates() {

  }

  TextureComponent::~TextureComponent() {}

  TextureComponent::TextureComponent(
      EMBER_COMPONENT m_componentType,
      const std::string &m_texture,
      const Dimension2d &m_dimension,
      EventBus *m_bus
  )
      : ComponentInterface(m_componentType)
        , m_texture(m_texture)
        , m_dimension(m_dimension)
        , m_bus(m_bus) {}
}
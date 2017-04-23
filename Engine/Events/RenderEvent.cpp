//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <iostream>
#include "RenderEvent.h"

namespace Ember {
  std::string RenderEvent::getType() {
    return "render_event";
  }

  RenderEvent::~RenderEvent() {
  }

  EventMessage RenderEvent::getMessage() {
    EventMessage message = EventMessage();
    message.name = m_name;
    message.dimension = m_dimension;
    message.position = m_position;
    return message;
  }

  RenderEvent::RenderEvent(
      Position2d m_position,
      Dimension2d m_dimension,
      const std::string &m_name
  )
      : m_position(m_position)
        , m_dimension(m_dimension)
        , m_name(m_name) {
  }
}
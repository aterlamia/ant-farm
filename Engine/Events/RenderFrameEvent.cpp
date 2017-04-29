//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "RenderFrameEvent.h"

namespace Ember {
  EventMessage RenderFrameEvent::getMessage() {
    EventMessage message = EventMessage();
    message.name = m_name;
    message.dimension = m_dimension;
    message.position = m_position;
    message.frame = m_frame;
    return message;
  }

  std::string RenderFrameEvent::getType() {
    return "render_frame";
  }

  RenderFrameEvent::RenderFrameEvent(
      const Vector2D &m_position,
      const Dimension2d &m_dimension,
      const Frame &m_frame,
      const std::string &m_name
  )
      : m_name(m_name)
        , m_position(m_position)
        , m_dimension(m_dimension)
        , m_frame(m_frame) {}
}

//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "MouseEvent.h"

namespace Ember {
  std::string MouseEvent::getType() {
    return "mouse_event";
  }

  EventMessage MouseEvent::getMessage() {
    EventMessage message = EventMessage();
    message.mousePosition = m_position;
    message.mouseButton = m_button;
    return message;
  }

  MouseEvent::MouseEvent(
      EmberEventType eventType,
      mouse_buttons button,
      const Vector2D &position
  )
      : m_eventType(eventType)
        , m_button(button)
        , m_position(position) {}


}
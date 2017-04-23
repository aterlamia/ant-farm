//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "InputEvent.h"

namespace Ember {
  std::string Ember::InputEvent::getType() {
    return "input_event";
  }

  EventMessage InputEvent::getMessage() {
    EventMessage message = EventMessage();
    message.eventType = m_eventType;
    message.key = m_key;
    return message;
  }

  InputEvent::InputEvent(
      EmberEventType m_eventType,
      SDL_Scancode m_key
  ) : m_eventType(m_eventType)
      , m_key(m_key) {}

  InputEvent::InputEvent(EmberEventType m_eventType) : m_eventType(m_eventType) {}
}

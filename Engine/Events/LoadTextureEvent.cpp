//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "LoadTextureEvent.h"

namespace Ember {
  std::string LoadTextureEvent::getType() {
    return "texture_load";
  }

  EventMessage LoadTextureEvent::getMessage() {
    EventMessage message = EventMessage();
    message.name = m_name;
    message.file = m_file;
    return message;
  }

  LoadTextureEvent::LoadTextureEvent(
      const std::string &m_name,
      const std::string &m_file
  ) : m_name(m_name)
      , m_file(m_file) {}
}
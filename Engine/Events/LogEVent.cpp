//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "LogEVent.h"

namespace Ember {
  std::string LogEVent::getType() {
    return "log";
  }

  LogEVent::LogEVent(
      const std::string &m_message,
      LOG_CANAL m_canal,
      LOG_TYPE m_type
  )
      : m_message(m_message)
        , m_canal(m_canal)
        , m_type(m_type) {}

  EventMessage LogEVent::getMessage() {
    EventMessage message = EventMessage();
    message.canal = m_canal;
    message.logType = m_type;
    message.message = m_message;
    return message;
  }
}

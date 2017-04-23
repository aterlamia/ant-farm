//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_LOGEVENT_H
#define EMBERENGINE_LOGEVENT_H

#include "EventInterface.h"
#include "../System/Logger.h"

namespace Ember {
  class LogEVent : public EventInterface {
  public:
    EventMessage getMessage() override;

    std::string getType() override;

  public:
    LogEVent(
        const std::string &m_message,
        LOG_CANAL m_canal,
        LOG_TYPE m_type
    );

  protected:
    std::string m_message;
    LOG_CANAL m_canal;
    LOG_TYPE m_type;
  };
};


#endif //EMBERENGINE_LOGEVENT_H

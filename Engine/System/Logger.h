//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_LOGGER_H
#define EMBERENGINE_LOGGER_H

#include "../Events/EventListenerInterface.h"
#include "LogEnums.h"
#include "../Events/LogEVent.h"

namespace Ember {

  class LogEVent;

  class Logger : public EventListenerInterface {
  public:

    void log(
        std::string message,
        LOG_CANAL canal
    );

    void error(
        std::string message,
        LOG_CANAL canal
    );

    void warning(
        std::string message,
        LOG_CANAL canal
    );

    void info(
        std::string message,
        LOG_CANAL canal
    );

    void handleEvent(EventInterface &event);

    bool shouldLogChannel(LOG_CANAL canal);

  private:
    std::string getTextualCanal(LOG_CANAL canal);

    int m_canalFilter = ALL;
  };
};


#endif //EMBERENGINE_LOGGER_H

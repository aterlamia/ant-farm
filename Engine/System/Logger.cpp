//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "Logger.h"

namespace Ember {

  void Logger::log(
      std::string message,
      LOG_CANAL canal
  ) {
    std::cout << getTextualCanal(canal) << " : " << message << " - " << "\n";
  }

  void Logger::error(
      std::string message,
      LOG_CANAL canal
  ) {
    if (shouldLogChannel(canal)) {
      std::cout << "\033[1;31mERROR:   \033[0m";
      std::cout << "\033[1;39m(" << getTextualCanal(canal) << ")\033[0m: " << message << "\n";
    }
  }

  void Logger::warning(
      std::string message,
      LOG_CANAL canal
  ) {
    if (shouldLogChannel(canal)) {
      std::cout << "\033[1;33mWARNING: \033[0m";
      std::cout << "\033[1;39m(" << getTextualCanal(canal) << ")\033[0m: " << message << "\n";
    }
  }

  void Logger::info(
      std::string message,
      LOG_CANAL canal
  ) {
    if (shouldLogChannel(canal)) {
      std::cout << "\033[1;32mINFO:    \033[0m";
      std::cout << "\033[1;39m(" << getTextualCanal(canal) << ")\033[0m: " << message << "\n";
    }
  }

  /**
   * I know now better (easier way) to get a textual repesentation of a enum.
   *
   * @return
   */
  std::string Logger::getTextualCanal(LOG_CANAL canal) {
    switch (canal) {
      case CONSTRUCTOR :
        return "CONSTRUCTOR";
      case DEBUG :
        return "DEBUG";
      case TEST :
        return "TEST";
      case SOUND :
        return "SOUND";
      case DESTRUCTOR :
        return "DESTRUCTOR";
      case TEXTURES :
        return "TEXTURES";
      case FPS :
        return "FPS";
      case LIBRARY :
        return "LIBRARY";
      case SDL :
        return "SDL";
      case INPUT:
        return "INPUT";
      case ASSETS:
        return "ASSETS";
      default:
        return "UNKNOWN";

    }
  }

  bool Logger::shouldLogChannel(LOG_CANAL canal) {
    if ((m_canalFilter & canal) > 0) {
      return true;
    }
    return false;
  }

  void Logger::handleEvent(EventInterface &event) {
    if (event.getType() != "log") {
      return;
    }

    EventMessage message = event.getMessage();

    switch (message.logType) {
      case ERROR_TYPE:
        error(message.message, message.canal);
        break;
      case WARNING_TYPE:
        warning(message.message, message.canal);
        break;
      case INFO_TYPE:
      default:
        info(message.message, message.canal);
    }
  }
}

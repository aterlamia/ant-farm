//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "GameState.h"

namespace Ember {
  bool GameState::isRunning() const {
    return m_running;
  }

  void GameState::setRunning(bool running) {
    m_running = running;
  }

  void GameState::handleEvent(EventInterface &event) {
    if (event.getType() != "input_event") {
      return;
    }

    EventMessage message = event.getMessage();

    if (message.eventType == QUIT_EVENT) {
      m_running = false;
    }

    if (message.eventType == KEYBOARD_EVENT_DOWN && message.key == SDL_SCANCODE_ESCAPE) {
      m_running = false;
    }
  }
}

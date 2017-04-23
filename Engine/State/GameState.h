//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_GAMESTATE_H
#define EMBERENGINE_GAMESTATE_H

#include "../Events/EventListenerInterface.h"

namespace Ember {
  class GameState : public EventListenerInterface {
  private:
  public:
    void handleEvent(EventInterface &event) override;

  private:
    bool m_running = false;
  public:
    bool isRunning() const;

    void setRunning(bool running);
  };
};

#endif //EMBERENGINE_GAMESTATE_H

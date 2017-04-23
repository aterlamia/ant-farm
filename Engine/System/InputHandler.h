//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_INPUTHANDLER_H
#define EMBERENGINE_INPUTHANDLER_H

#include  <SDL2/SDL.h>
#include "../Events/EventBus.h"

namespace Ember {
  class InputHandler {
  public:
    /**
     * Handles keyboard and/or mouse input.
     *
     * Will fire an event that other listeners can subcribe too,
     */
    void handleInput();

    virtual ~InputHandler();;
  private:
  public:
    InputHandler(EventBus *m_bus);

  private:
    EventBus *m_bus;
  };

};


#endif //EMBERENGINE_INPUTHANDLER_H

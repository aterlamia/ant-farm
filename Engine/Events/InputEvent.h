//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_INPUTEVENT_H
#define EMBERENGINE_INPUTEVENT_H

#include <SDL_scancode.h>
#include "EventInterface.h"
#include "EventMessage.h"

namespace Ember {
  class InputEvent : public EventInterface {
  public:
    InputEvent(
        EmberEventType m_eventType,
        SDL_Scancode m_key
    );

    InputEvent(EmberEventType m_eventType);

    std::string getType() override;

    EventMessage getMessage() override;

  private:
    EmberEventType m_eventType;
    SDL_Scancode m_key;
  };
};


#endif //EMBERENGINE_INPUTEVENT_H

//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_MOUSEEVENT_H
#define EMBERENGINE_MOUSEEVENT_H

#include "EventMessage.h"
#include "EventInterface.h"

namespace Ember {

  class MouseEvent : public EventInterface {
  public:

    std::string getType() override;

    EventMessage getMessage() override;

    MouseEvent(
        EmberEventType eventType,
        mouse_buttons button,
        const Position2d &position
    );

  private:
    EmberEventType m_eventType;
    mouse_buttons m_button;
    Position2d m_position;
  };

};

#endif //EMBERENGINE_MOUSEEVENT_H

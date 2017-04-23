//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_EVENTTYPE_H
#define EMBERENGINE_EVENTTYPE_H

namespace Ember {
  struct EventMessage;
  typedef enum {
    KEYBOARD_EVENT_UP,
    KEYBOARD_EVENT_DOWN,
    QUIT_EVENT,
    MOUSE_DOWN,
    MOUSE_UP
  } EmberEventType;

  enum mouse_buttons {
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
  };
}

#endif //EMBERENGINE_EVENTTYPE_H

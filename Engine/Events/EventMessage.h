//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_EVENTMESSAGE_H
#define EMBERENGINE_EVENTMESSAGE_H

#include <SDL_scancode.h>
#include "string"
#include "../ValueObjects/Dimension2d.h"
#include "../ValueObjects/Position2d.h"
#include "../ValueObjects/Frame.h"
#include "EventType.h"
#include "../System/LogEnums.h"
#include "../Objects/GameObject.h"

namespace Ember {
  struct EventMessage {
    std::string message;
    LOG_CANAL canal;
    LOG_TYPE logType;
    std::string file;
    std::string name;
    EmberEventType eventType;
    SDL_Scancode key;
    Dimension2d dimension = {0.0, 0.0};
    Position2d position = {0.0, 0.0};
    Frame frame = {0, 0};
    mouse_buttons mouseButton;
    Position2d mousePosition = {0.0, 0.0};
    GameObject *object;
  };
};

#endif //EMBERENGINE_EVENTMESSAGE_H

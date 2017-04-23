//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "BuildEvent.h"

std::string BuildEvent::getType() {
  return "build_event";
}

Ember::EventMessage BuildEvent::getMessage() {
  Ember::EventMessage message = Ember::EventMessage();

  return message;
}

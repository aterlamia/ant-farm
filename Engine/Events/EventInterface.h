//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_EVENTINTERFACE_H
#define EMBERENGINE_EVENTINTERFACE_H

#include <iostream>
#include "string"
#include "EventMessage.h"

namespace Ember {
  class EventInterface {

  public:
    virtual ~EventInterface() {}

    virtual std::string getType() = 0;

    virtual EventMessage getMessage() = 0;
  };
};

#endif //EMBERENGINE_EVENTINTERFACE_H


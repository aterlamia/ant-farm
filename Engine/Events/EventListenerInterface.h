//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_EVENTLISTENERINTERFACE_H
#define EMBERENGINE_EVENTLISTENERINTERFACE_H

#include "EventInterface.h"

namespace Ember {
  class EventListenerInterface {
  public:
    virtual void handleEvent(EventInterface &event) = 0;
  };
};

#endif //EMBERENGINE_EVENTLISTENERINTERFACE_H

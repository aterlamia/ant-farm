//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_EVENTBUS_H
#define EMBERENGINE_EVENTBUS_H

#include <vector>
#include "EventListenerInterface.h"

namespace Ember {
  class EventBus {
  private:
    std::vector<EventListenerInterface *> m_eventListeners;
  public:
    void subscribe(EventListenerInterface *listener);

    void fire(EventInterface *test);
  };
};


#endif //EMBERENGINE_EVENTBUS_H

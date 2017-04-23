//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "EventBus.h"

namespace Ember {
  void EventBus::subscribe(Ember::EventListenerInterface *listener) {
    m_eventListeners.push_back(listener);
  }

  void EventBus::fire(EventInterface *event) {

    for (std::vector<Ember::EventListenerInterface *>::size_type i = 0; i != m_eventListeners.size(); i++) {
      m_eventListeners[i]->handleEvent(*event);
    }

    // All listeners called now remove event as we don't need it anymore;
    delete (event);
  }
}

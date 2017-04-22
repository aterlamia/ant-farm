//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_BUILDEVENT_H
#define ANTFARM_BUILDEVENT_H


#include <Events/EventInterface.h>

class BuildEvent : public Ember::EventInterface {
public:
  std::string getType() override;

  Ember::EventMessage getMessage() override;
};


#endif //ANTFARM_BUILDEVENT_H

//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_EVENTMESSAGE_H
#define ANTFARM_EVENTMESSAGE_H

#include <Events/EventMessage.h>
#include "../Components/Tile.h"

struct EventMessage : public Ember::EventMessage {
  Tile *tile;
};
#endif //ANTFARM_EVENTMESSAGE_H

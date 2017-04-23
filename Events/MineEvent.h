//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_MINEEVENT_H
#define ANTFARM_MINEEVENT_H


#include <Events/EventInterface.h>
#include "../Components/Tile.h"

class MineEvent : public Ember::EventInterface {
public:
  std::string getType() override;

  MineEvent(
      Tile *m_tile,
      const Ember::Position2d &m_position
  );

  Ember::EventMessage getMessage() override;
  Ember::Position2d m_position;

protected:
  Tile *m_tile;
};

#endif //ANTFARM_MINEEVENT_H

//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_TILEOBJECT_H
#define ANTFARM_TILEOBJECT_H

#include <Objects/GameObject.h>
#include <ValueObjects/Position2d.h>

class TileObject : public Ember::GameObject {
public:
  TileObject(
        const std::string &m_name,
        Ember::Position2d m_position
    );

protected:
  Ember::Position2d m_position;
};


#endif //ANTFARM_TILEOBJECT_H

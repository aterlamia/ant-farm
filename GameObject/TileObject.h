//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_TILEOBJECT_H
#define ANTFARM_TILEOBJECT_H

#include <Objects/GameObject.h>
#include <ValueObjects/Vector2D.h>

class TileObject : public Ember::GameObject {
public:
  TileObject(
      const std::string &m_name,
      Ember::Vector2D m_position
  );

protected:
  bool minable = false;

public:
  bool isMinable() const;
  void setMinable(bool minable);
  bool isPassable() const;
  void setPassable(bool passable);
  int getHealth() const;
  void setHealth(int health);
protected:
  bool passable = false;
  int health = 100;
};


#endif //ANTFARM_TILEOBJECT_H

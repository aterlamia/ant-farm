//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_RENDEREVENT_H
#define EMBERENGINE_RENDEREVENT_H

#include "EventInterface.h"
#include "../ValueObjects/Position2d.h"
#include "../ValueObjects/Dimension2d.h"

namespace Ember {
  class RenderEvent : public EventInterface {
  protected:
    Position2d m_position;
    Dimension2d m_dimension;
    std::string m_name;
  public:
    std::string getType() override;

    EventMessage getMessage() override;

    RenderEvent(
        Position2d m_position,
        Dimension2d m_dimension,
        const std::string &m_name
    );

    virtual ~RenderEvent();
  };
};


#endif //EMBERENGINE_RENDEREVENT_H

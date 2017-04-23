//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_RENDERFRAMEEVENT_H
#define EMBERENGINE_RENDERFRAMEEVENT_H

#include "EventInterface.h"
#include "../ValueObjects/Position2d.h"
#include "../ValueObjects/Dimension2d.h"
#include "RenderEvent.h"
#include "../ValueObjects/Frame.h"

namespace Ember {
  class RenderFrameEvent : public EventInterface {
  protected:
    std::string m_name;

    Position2d m_position;
    Dimension2d m_dimension;
    Frame m_frame;
  public:
    RenderFrameEvent(
        const Position2d &m_position,
        const Dimension2d &m_dimension,
        const Frame &m_frame,
        const std::string &m_name
    );

  public:

    std::string getType() override;


    EventMessage getMessage() override;
  };
};


#endif //EMBERENGINE_RENDERFRAMEEVENT_H

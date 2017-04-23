//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_TEXTURECOMPONENT_H
#define EMBERENGINE_TEXTURECOMPONENT_H

#include "ComponentInterface.h"
#include "../Events/EventBus.h"
#include "../ValueObjects/Position2d.h"
#include "../ValueObjects/Dimension2d.h"
#include <string>

namespace Ember {
  class TextureComponent : public ComponentInterface {
  protected:
    std::string m_texture;
  public:
    TextureComponent(
        EMBER_COMPONENT m_componentType,
        const std::string &m_texture,
        const Position2d &m_position,
        const Dimension2d &m_dimension,
        EventBus *m_bus
    );

  protected:
    Position2d m_position;
    Dimension2d m_dimension;
    EventBus *m_bus;
  public:

    virtual ~TextureComponent();

    void handleGraphical() override;

    void handleInput() override;

    void handleUpdates() override;

  };
};


#endif //EMBERENGINE_TEXTURECOMPONENT_H

//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_TILEDTEXTURECOMPONENT_H
#define EMBERENGINE_TILEDTEXTURECOMPONENT_H

#include "TextureComponent.h"
#include "../ValueObjects/Frame.h"

namespace Ember {

  class TiledTextureComponent : public TextureComponent {
  protected:
    Frame m_frame;
  public:
    void handleGraphical() override;

    TiledTextureComponent(
        EMBER_COMPONENT m_componentType,
        const std::string &m_texture,
        const Dimension2d &m_dimension,
        const Frame &m_frame,
        EventBus *m_bus
    );

    void setFrame(const Frame &m_frame);

  };

};


#endif //EMBERENGINE_TILEDTEXTURECOMPONENT_H

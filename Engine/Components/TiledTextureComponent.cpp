//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "TiledTextureComponent.h"
#include "../Events/RenderFrameEvent.h"

namespace Ember {
  /**
   * Constructor.
   *
   * @param m_componentType
   * @param m_texture
   * @param m_position
   * @param m_dimension
   * @param m_frame
   * @param m_bus
   */
  TiledTextureComponent::TiledTextureComponent(
      EMBER_COMPONENT m_componentType,
      const std::string &m_texture,
      const Position2d &m_position,
      const Dimension2d &m_dimension,
      const Frame &m_frame,
      EventBus *m_bus
  )
      : TextureComponent(m_componentType, m_texture, m_position, m_dimension, m_bus)
        , m_frame(m_frame) {}

  /**
   * Handle rendering or other graphic stuff.
   */
  void TiledTextureComponent::handleGraphical() {
    m_bus->fire(
        new RenderFrameEvent(
            m_position,
            m_dimension,
            m_frame,
            m_texture
        )
    );
  }

  /**
   * Change frame that needs to be renderd.
   *
   * @param m_frame
   */
  void TiledTextureComponent::setFrame(const Frame &m_frame) {
    TiledTextureComponent::m_frame = m_frame;
  }


}
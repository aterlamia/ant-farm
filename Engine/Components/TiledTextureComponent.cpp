//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "TiledTextureComponent.h"
#include "../../System/ServiceContainer.h"

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
      const Dimension2d &m_dimension,
      const Frame &m_frame,
      EventBus *m_bus
  )
      : TextureComponent(m_componentType, m_texture, m_dimension, m_bus)
        , m_frame(m_frame) {}

  /**
   * Handle rendering or other graphic stuff.
   */
  void TiledTextureComponent::handleGraphical() {
    ServiceContainer::GetInstance()->getTextureManager().drawFrame(
        m_texture,
        m_object->getPosition().X,
        m_object->getPosition().Y,
        m_dimension.width,
        m_dimension.height,
        m_frame.row,
        m_frame.column
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
//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include <SDL_timer.h>
#include "AnimationComponent.h"

namespace Ember {
  void AnimationComponent::handleGraphical() {

  }

  void AnimationComponent::handleInput() {

  }

  void AnimationComponent::handleUpdates() {
    m_currentFrame = m_sets[m_currentSet][int(((SDL_GetTicks() / 100) % m_sets[m_currentSet].size()))];
  }

  void AnimationComponent::addSet(
      std::string name,
      std::vector<Frame> set
  ) {
    m_sets[name] = set;
  }

  AnimationComponent::AnimationComponent(EMBER_COMPONENT m_componentType)
      : ComponentInterface(m_componentType) {}
}
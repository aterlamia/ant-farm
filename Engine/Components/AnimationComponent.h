//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_ANIMATIONCOMPONENT_H
#define EMBERENGINE_ANIMATIONCOMPONENT_H

#include <map>
#include <vector>
#include "ComponentInterface.h"
#include "../ValueObjects/Frame.h"

namespace Ember {
  class AnimationComponent : public ComponentInterface {
  public:
    AnimationComponent(EMBER_COMPONENT m_componentType);

    void handleGraphical() override;

    void handleInput() override;

    void handleUpdates() override;

    virtual void addSet(
        std::string name,
        std::vector<Frame> set
    );

  protected:
    std::map<std::string, std::vector<Frame>> m_sets;
    Frame m_currentFrame = Ember::Frame(0, 0);
    std::string m_currentSet = "default";
  };
};


#endif //EMBERENGINE_ANIMATIONCOMPONENT_H

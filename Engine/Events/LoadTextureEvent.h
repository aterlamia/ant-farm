//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_LOADTEXTUREEVENT_H
#define EMBERENGINE_LOADTEXTUREEVENT_H


#include "EventInterface.h"

namespace Ember {
  class LoadTextureEvent : public EventInterface {
  public:
    std::string getType() override;

    EventMessage getMessage() override;

  private:

    std::string m_name;
  public:
    LoadTextureEvent(
        const std::string &m_name,
        const std::string &m_file
    );

  private:
    std::string m_file;
  };
};


#endif //EMBERENGINE_LOADTEXTUREEVENT_H

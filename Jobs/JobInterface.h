//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_JOBINTERFACE_H
#define ANTFARM_JOBINTERFACE_H

#include "ValueObjects/Position2d.h"
// Forward declare ant.
// Todo probably make a worker class
class Ant;

class JobInterface {
public:
  virtual void doJob() = 0;

  virtual void setWorker(Ant *worker);

  virtual bool hasWorker();

  virtual void removeWorker() = 0;
  JobInterface(const Ember::Position2d &m_position);

  const Ember::Position2d &getPosition() const {
    return m_position;
  }

protected:
  int m_time;
  Ant *m_worker = nullptr;
  Ember::Position2d m_position = {0.0, 0.0};

};


#endif //ANTFARM_JOBINTERFACE_H

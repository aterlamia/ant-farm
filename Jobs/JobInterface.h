//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_JOBINTERFACE_H
#define ANTFARM_JOBINTERFACE_H


#include "../Components/Ant.h"

class JobInterface {
public:
  virtual void doJob() = 0;

  virtual void setWorker() = 0;

  virtual void removeWorker() = 0;

protected:
  int m_time;
//  Ant *m_worker;
};


#endif //ANTFARM_JOBINTERFACE_H

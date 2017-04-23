//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_MINEJOB_H
#define ANTFARM_MINEJOB_H


#include "JobInterface.h"

class MineJob : public JobInterface {
public:
  void doJob() override;
  MineJob(const Ember::Position2d &m_position);
  void setWorker();
  void removeWorker() override;
};


#endif //ANTFARM_MINEJOB_H

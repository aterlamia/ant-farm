//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_MINEJOB_H
#define ANTFARM_MINEJOB_H


#include "JobInterface.h"

class MineJob : public JobInterface {
protected:
  Ember::Position2d m_position = {0.0, 0.0};

public:
  MineJob(const Ember::Position2d &m_position);
  void doJob() override;
  void setWorker() override;
  void removeWorker() override;
};


#endif //ANTFARM_MINEJOB_H

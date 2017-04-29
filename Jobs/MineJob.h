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
  MineJob(const Ember::Vector2D &m_position);
  void setWorker();
  void removeWorker() override;
};


#endif //ANTFARM_MINEJOB_H

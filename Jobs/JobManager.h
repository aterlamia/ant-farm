//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef ANTFARM_JOBMANAGER_H
#define ANTFARM_JOBMANAGER_H


#include "JobInterface.h"

class JobManager : public Ember::EventListenerInterface {
public:
  JobInterface *getFreeJob();

  void handleEvent(Ember::EventInterface &event) override;

  void addJob(JobInterface *job);

protected:
  std::vector<JobInterface *> m_jobs;
};


#endif //ANTFARM_JOBMANAGER_H
//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "JobManager.h"
#include "MineJob.h"

JobInterface *JobManager::getFreeJob() {
  return nullptr;
}

void JobManager::addJob(JobInterface *job) {
  std::cout << "Job added";
  m_jobs.push_back(job);
}

void JobManager::handleEvent(Ember::EventInterface &event) {

  if (event.getType() == "mine_event") {

    std::cout << "tester";
    Ember::EventMessage message = event.getMessage();

    MineJob *mineJob = new MineJob(message.position);

    m_jobs.push_back(mineJob);
  }
}

void JobManager::handleEvent(MineEvent &event) {
  std::cout << "tester de test";
}

//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "JobManager.h"

JobInterface *JobManager::getFreeJob() {
  return nullptr;
}

void JobManager::addJob(JobInterface *job) {
  std::cout << "Job added";
  m_jobs.push_back(job);
}

void JobManager::handleEvent(Ember::EventInterface &event) {

  if (event.getType() == "mine_event") {
    std::cout << event.getType();
  }
}

//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "JobManager.h"
#include "MineJob.h"

JobInterface *JobManager::getFreeJob() {
//
//  for (std::vector<JobInterface *>::size_type i = 0; i != m_jobs.size(); i++) {
//    if (m_jobs[i]->hasWorker() == false) {
//
//    }
//  }

  return nullptr;
}


JobInterface *JobManager::assingJob(Ant *ant) {
  for (std::vector<JobInterface *>::size_type i = 0; i != m_jobs.size(); i++) {
    if (m_jobs[i]->hasWorker() == false) {
      m_jobs[i]->setWorker(ant);

      return m_jobs[i];
    }
  }
}

void JobManager::addJob(JobInterface *job) {
  m_jobs.push_back(job);
}

void JobManager::handleEvent(Ember::EventInterface &event) {

  if (event.getType() == "mine_event") {
    Ember::EventMessage message = event.getMessage();

    MineJob *mineJob = new MineJob(message.position);

    m_jobs.push_back(mineJob);
  }
}

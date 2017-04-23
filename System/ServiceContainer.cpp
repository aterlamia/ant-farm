//
// Created by melvin on 30-8-16.
//
#include "ServiceContainer.h"

ServiceContainer* ServiceContainer::instance = nullptr;

JobManager *ServiceContainer::m_jobManager = 0;

void ServiceContainer::Initialize() {

}

JobManager &ServiceContainer::getJobManager() {
  return *m_jobManager;
}

void ServiceContainer::Provide(JobManager *service) {
  m_jobManager = service;
}

ServiceContainer::ServiceContainer() {}

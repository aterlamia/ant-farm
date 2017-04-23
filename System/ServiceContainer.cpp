//
// Created by melvin on 30-8-16.
//
#include "ServiceContainer.h"

/**
 * Constructor.
 */
ServiceContainer::ServiceContainer() {}

ServiceContainer *ServiceContainer::instance = nullptr;

JobManager *ServiceContainer::m_jobManager = 0;
SceneManager *ServiceContainer::m_sceneManager = 0;

void ServiceContainer::Provide(SceneManager *service) {
  m_sceneManager = service;
}

void ServiceContainer::Provide(JobManager *service) {
  m_jobManager = service;
}

SceneManager &ServiceContainer::getSceneManager() {
  return *m_sceneManager;
}

JobManager &ServiceContainer::getJobManager() {
  return *m_jobManager;
}

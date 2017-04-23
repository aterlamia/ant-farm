//
// Created by Aterlamia.
// Part of the Ember-engine
//

#include "../Components/Ant.h"

void JobInterface::setWorker(Ant *worker) {
  m_worker = worker;
}

bool JobInterface::hasWorker() {
  return m_worker != nullptr;
}

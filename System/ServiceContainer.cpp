//
// Created by melvin on 30-8-16.
//
#include "ServiceContainer.h"

Ember::Logger::iLogger *Ember::ServiceContainer::mvpLoggerService = 0;

Ember::Logger::iLogger &Ember::ServiceContainer::getLogger() { return *mvpLoggerService; }

void Ember::ServiceContainer::Provide(Ember::Logger::iLogger *service) {
  mvpLoggerService = service;
}

void Ember::ServiceContainer::Initialize() {
}

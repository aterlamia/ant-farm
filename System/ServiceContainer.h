#ifndef EMBER_SERVICECONTAINER_H
#define EMBER_SERVICECONTAINER_H

#include "../Jobs/JobManager.h"
#include "../Layer/LayerManager.h"

class ServiceContainer {
private:
  static JobManager *m_jobManager;
  ServiceContainer();
  static ServiceContainer *instance;

public:

  static ServiceContainer *const GetInstance() {
    if (instance == nullptr) {
      instance = new ServiceContainer();
    }

    return instance;
  }

  static void Initialize();

  static JobManager &getJobManager();

  /**
   * @param service
   */
  static void Provide(JobManager *service);

};

#endif //EMBER_SERVICECONTAINER_H

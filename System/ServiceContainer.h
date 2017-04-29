#ifndef EMBER_SERVICECONTAINER_H
#define EMBER_SERVICECONTAINER_H

#include <SceneManager.h>
#include <Assets/TextureManager.h>
#include "../Jobs/JobManager.h"
#include "../Layer/LayerManager.h"

class ServiceContainer {
private:
  static JobManager *m_jobManager;
  static SceneManager *m_sceneManager;
  static Ember::TextureManager *m_textureManager;
  static ServiceContainer *instance;

  ServiceContainer();

public:
/**
 * Singleton
 * @return
 */
  static ServiceContainer *const GetInstance() {
    if (instance == nullptr) {
      instance = new ServiceContainer();
    }

    return instance;
  }

  static JobManager &getJobManager();
  static SceneManager &getSceneManager();
  static Ember::TextureManager &getTextureManager();

  static void Provide(JobManager *service);
  static void Provide(SceneManager *service);
  static void Provide(Ember::TextureManager *service);

};

#endif //EMBER_SERVICECONTAINER_H

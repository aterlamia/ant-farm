#ifndef EMBERENGINE_STATICASSETLOADER_H
#define EMBERENGINE_STATICASSETLOADER_H

#include <Events/EventBus.h>
#include <Assets/AssetLoaderInterface.h>

class StaticAssetLoader : public Ember::AssetLoaderInterface {
protected:
  Ember::EventBus *m_bus;

public:
  StaticAssetLoader(Ember::EventBus *bus);

  void loadAssets();
};

#endif //EMBERENGINE_STATICASSETLOADER_H

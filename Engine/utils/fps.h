#ifndef EMBER_FPS_H
#define EMBER_FPS_H

#include <iosfwd>
#include <sstream>
#include <iostream>
#include "Interval.h"

class Fps {
 protected:
  unsigned int mtFps;
  unsigned int mtFpsCount;
  Interval mtFpsInterval;
  Interval mtFpsRenderInterval;
  std::stringstream mtTimeText;

 public:
  // Constructor
  Fps() : mtFps(0), mtFpsCount(0) {
  }

  // Update
  void update() {
    // increase the counter by one
    mtFpsCount++;

    // one second elapsed? (= 1000 milliseconds)
    if (mtFpsInterval.getValue() > 1000) {
      // save the current counter getValue to mtFps
      mtFps = mtFpsCount;

      // reset the counter and the interval
      mtFpsCount = 0;
      mtFpsInterval = Interval();
      //Set text to be rendered
      mtTimeText.str("");
      mtTimeText << "FPS: " << mtFps << "\n";
    }
  }
  virtual ~Fps() {
//    Ember::ServiceContainer::getLogger().Info("fps ", Ember::Logger::iLogger::LOG_CANAL::DESTRUCTOR);
  }

  void Render() {
    if (mtFpsRenderInterval.getValue() > 5000) {
//      Ember::ServiceContainer::getLogger().Info(mtTimeText.str().c_str(), Ember::Logger::iLogger::LOG_CANAL::FPS);

      std::cout << mtTimeText.str().c_str();
      mtFpsRenderInterval = Interval();
    }
  }
};

#endif //EMBER_FPS_H

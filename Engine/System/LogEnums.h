//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_LOGENUMS_H
#define EMBERENGINE_LOGENUMS_H
namespace Ember {
  enum LOG_CANAL {
    DEBUG = 1,
    TEST = 2,
    SOUND = 4,
    INPUT = 8,
    CONSTRUCTOR = 16,
    DESTRUCTOR = 32,
    TEXTURES = 64,
    FPS = 128,
    SDL = 256, // We are working with sdl so have a sdl specific canal.
    LIBRARY = 512, // Library canal for any other library we might use.
    ASSETS = 1024,
    ALL = 2047, // All of the above don't forget new canal means ALL has to be re calculated.
  };

  enum LOG_TYPE {
    DEBUG_TYPE = 1,
    WARNING_TYPE = 2,
    ERROR_TYPE = 4,
    INFO_TYPE = 8,
  };
};
#endif //EMBERENGINE_LOGENUMS_H

//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_DIMENSION2D_H
#define EMBERENGINE_DIMENSION2D_H
namespace Ember {
  struct Dimension2d {
    Dimension2d(
        float height,
        float width
    )
        : height(height)
          , width(width) {};

    float height;
    float width;
  };
}
#endif //EMBERENGINE_DIMENSION2D_H

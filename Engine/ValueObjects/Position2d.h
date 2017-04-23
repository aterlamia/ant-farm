//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_POSITION2D_H
#define EMBERENGINE_POSITION2D_H
namespace Ember {
  struct Position2d {
    Position2d(
        float X,
        float Y
    ) : X(X)
        , Y(Y) {}

    float X;
    float Y;
  };
}
#endif //EMBERENGINE_POSITION2D_H
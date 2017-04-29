//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_POSITION2D_H
#define EMBERENGINE_POSITION2D_H

#include <Math/Vector2d.h>

namespace Ember {
  class Vector2D {
  public:
    Vector2D(
        float X,
        float Y
    ) : X(X)
        , Y(Y) {}

    float X;
    float Y;

    bool equals(Vector2D compare) {
      return X == compare.X && Y == compare.Y;
    }

    /**
  * Add functoion will do an add operation to this vector
  * ```
  *     Vector add operation is simple y adding y to y an dx to x
  *    EXAMPLE:
  *      Vector(1,3) + Vector(2,4) = Vector (3, 7)
  * ```
  * @param vector2
  */
    void Add(Vector2D &vector2) {
      X += vector2.X;
      Y += vector2.Y;
    }

    /**
     * Assignment operator for cout. This will allow for easier logging of the vector postions.
     *
     * @param out The ostream we want to output the text to.
     * @param vector This class with all info.
     * @return
     */
    friend std::ostream &operator<<(std::ostream &out, const Vector2D &vector) {
      out << "vector(" << vector.X << "," << vector.Y << ")";
      return out;
    }

    /**
     * Opperatior to add += operator function to this class, it will do teh same operation as add().
     * @param vector1 Current vector (this)
     * @param vector2 Vector to add to this vector.
     *
     * @return this vector after the changes.
     */
    friend Vector2D &operator+=(Vector2D &vector1, const Vector2D &vector2) {
      vector1.X += vector2.X;
      vector1.Y += vector2.Y;
      return vector1;
    }
  };
}
#endif //EMBERENGINE_POSITION2D_H

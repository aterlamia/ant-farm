//
// Created by Aterlamia.
// Part of the Ember-engine
//

#ifndef EMBERENGINE_VECTOR2D_H
#define EMBERENGINE_VECTOR2D_H

#include <iostream>

namespace Ember {
  class Vector2d {
  public:
    /**
     * Constructor for the Vector2d Class.
     *
     * @param x x position of vector.
     * @param y y position of vector.
     *
     * @return void
     */
    Vector2d(
        float x,
        float y
    ) : mvX(x)
        , mvY(y) {
    }

    /**
     *  Get set x.
     *
     * @return the set x position.
     */
    float getX() const {
      return mvX;
    }

    /**
    *  Get set y.
    *
    * @return the set y position.
    */
    float getY() const {
      return mvY;
    }

    /**
     * Give a new value to x.
     *
     * @param x the new x position
     */
    void setX(float x) {
      mvX = x;
    }

    /**
     * Give a new value to x.
     *
     * @param x the new x position
     */
    void setY(float y) {
      mvY = y;
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
    void Add(Vector2d &vector2) {
      mvX += vector2.mvX;
      mvY += vector2.mvY;
    }

    /**
     * Assignment operator for cout. This will allow for easier logging of the vector postions.
     *
     * @param out The ostream we want to output the text to.
     * @param vector This class with all info.
     * @return
     */
    friend std::ostream &operator<<(
        std::ostream &out,
        const Vector2d &vector
    ) {
      out << "vector(" << vector.getX() << "," << vector.getY() << ")";
      return out;
    }

    /**
     * Opperatior to add += operator function to this class, it will do teh same operation as add().
     * @param vector1 Current vector (this)
     * @param vector2 Vector to add to this vector.
     *
     * @return this vector after the changes.
     */
    friend Vector2d &operator+=(
        Vector2d &vector1,
        const Vector2d &vector2
    ) {
      vector1.mvX += vector2.mvX;
      vector1.mvY += vector2.mvY;
      return vector1;
    }

  private:
    float mvY;
    float mvX;
  };
};


#endif //EMBERENGINE_VECTOR2D_H

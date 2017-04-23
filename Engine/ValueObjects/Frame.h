//
// Value object that hold data for a frame in an animation.
//

#ifndef EMBER_FRAME_H
#define EMBER_FRAME_H

namespace Ember {
  struct Frame {
    /**
     * Constructor for the Frame valueobject,
     *
     * @param row What row does this object points to.
     * @param column What column does this object points to.
     *
     * @return void
     */
    Frame(
        int row,
        int column
    )
        : row(row)
          , column(column) {}

    virtual ~Frame() {
    }


    int row;
    int column;
  };
};

#endif //EMBER_FRAME_H

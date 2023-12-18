//
// Created by root on 12/12/23.
//

#ifndef W_MOVEABLE_H
#define W_MOVEABLE_H

#include "Drawable.h"

class Moveable : public Drawable {
public:
    Moveable(int rows, int cols, char initialChar = ' ', Vector2D topLeft = Vector2D()) : Drawable(rows, cols, initialChar, topLeft) {
        // Initialization for Moveable
    }
    virtual void handleEvent(int ch) {}
};
#endif //W_MOVEABLE_H

#ifndef W_DRAWABLE_H
#define W_DRAWABLE_H

#include <vector>
#include <ncurses.h>
#include "Vector2D.h"

class Drawable {
protected:
    std::vector<std::vector<char>> chs;

public:
    Vector2D top_left;
    Drawable(int rows, int cols, char initialChar = ' ', Vector2D topLeft = Vector2D());

    void draw(WINDOW* win) const;
    void setChar(int row, int col, char c);
    char getChar(int row, int col) const;

    virtual void start() = 0;
    virtual void update() = 0;
};

#endif //W_DRAWABLE_H

#include "Drawable.h"

Drawable::Drawable(int rows, int cols, char initialChar, Vector2D topLeft)
        : chs(rows, std::vector<char>(cols, initialChar)), top_left(topLeft) {}

void Drawable::draw(WINDOW* win) const {
    for (size_t i = 0; i < chs.size(); ++i) {
        for (size_t j = 0; j < chs[i].size(); ++j) {
            mvwaddch(win, i + top_left.getY(), j + top_left.getX(), chs[i][j]);
        }
    }
}


void Drawable::setChar(int row, int col, char c) {
    if (row >= 0 && static_cast<size_t>(row) < chs.size() &&
        col >= 0 && static_cast<size_t>(col) < chs[0].size()) {
        chs[row][col] = c;
    }
}

char Drawable::getChar(int row, int col) const {
    if (row >= 0 && static_cast<size_t>(row) < chs.size() &&
        col >= 0 && static_cast<size_t>(col) < chs[0].size()) {
        return chs[row][col];
    }
    return '\0';
}

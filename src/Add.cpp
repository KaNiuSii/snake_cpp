#include "Add.h"

Add::Add() : Moveable(3, 31, ' ', Vector2D(33,1)) {}

void Add::start() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 31; ++j) {
            if (i == 0 || i == 2 || j == 0 || j == 30) {
                setChar(i, j, '*');
            } else {
                setChar(i, j, ' ');
            }
        }
    }

    char text[] = "github.com/KaNiuSii/snake_cpp";

    for(int i = 0; text[i] != '\0'; i++)
    {
        setChar(1, i + 1, text[i]);
    }
}

void Add::handleEvent(int ch) {
    if(ch == KEY_UP)
    {
        this->top_left += Vector2D(0, -1);
    }
    if(ch == KEY_DOWN)
    {
        this->top_left += Vector2D(0, 1);
    }
    if(ch == KEY_RIGHT)
    {
        this->top_left += Vector2D(1, 0);
    }
    if(ch == KEY_LEFT)
    {
        this->top_left += Vector2D(-1, 0);
    }
}
#include "Instruction.h"

Instruction::Instruction() : Moveable(7, 19, ' ', Vector2D(70,8)) {}

void Instruction::start() {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 19; ++j) {
            if (i == 0 || i == 6 || j == 0 || j == 18) {
                setChar(i, j, '*');
            } else {
                setChar(i, j, ' ');
            }
        }
    }

    char secondRow[] = "     p - pause   ";
    char fourthRow[] = "     r - restart ";
    char  sixthRow[] = "  wsad - snake   ";
    char  eightRow[] = "     t - redirect";
    char  tenthRow[] = "arrows - move win";

    for(int i = 1; i < 18; i++)
    {
        setChar(5, i,  tenthRow[i - 1]);
        setChar(4, i,  eightRow[i - 1]);
        setChar(3, i,  sixthRow[i - 1]);
        setChar(2, i, fourthRow[i - 1]);
        setChar(1, i, secondRow[i - 1]);
    }
}

void Instruction::handleEvent(int ch) {
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
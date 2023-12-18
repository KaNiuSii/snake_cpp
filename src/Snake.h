#ifndef W_SNAKE_H
#define W_SNAKE_H

#include "Drawable.h"
#include "Moveable.h"
#include <list>

class Snake : public Moveable{
private:
    int speed = 16;
    std::list<Vector2D> snake_nodes;
    Vector2D head;
    Vector2D dir;
    bool paused;
    Vector2D food;
public:
    int level; 
    Snake();
    void start() override;
    void update() override;
    void handleEvent(int ch) override;
    void generateFood();
    void clear();
    void snake_draw();
    void end();
    void setup();
    void disp_paused();
    void disp_level();
};

#endif //W_SNAKE_H

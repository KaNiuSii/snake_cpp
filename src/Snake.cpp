#include "Snake.h"
#include <cstdlib>
#include <ctime>

Snake::Snake() : Moveable(10, 30, ' ', Vector2D(33,5)) {}

void Snake::start() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 30; ++j) {
            if (i == 0 || i == 9 || j == 0 || j == 29) {
                setChar(i, j, '*');
            } else {
                setChar(i, j, ' ');
            }
        }
    }
    end();
}

void Snake::setup() {
    disp_level();
    speed = 12;
    level = 0;
    paused = true;
    head = Vector2D(2, 15);
    dir = Vector2D(1, 0);
    snake_nodes.push_back(head);
    generateFood();
}

void Snake::disp_level() {
    char l[50];
    snprintf(l, sizeof(l), "LEVEL: %d ", level);
    for (int i = 0; l[i] != '\0'; i++)
    {
        setChar(0,i + 1,l[i]);
    }
}

void Snake::disp_paused() {
    char l[50];
    snprintf(l, sizeof(l), "Your level: %d", level);
    for (int i = 0; l[i] != '\0'; i++) {
        setChar(4, i + 8, l[i]);
    }
    snprintf(l, sizeof(l), "Press 'p' to play");
    for (int i = 0; l[i] != '\0'; i++) {
        setChar(6, i + 6, l[i]);
    }
}

void Snake::end() {
    snake_nodes.clear();
    paused = true;
    disp_paused();
    setup();
}

void Snake::clear()
{
    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 29; ++j) {
            setChar(i,j, ' ');
        }
    }
}

int count = 0;

void Snake::update() {
    if(paused)
    {

        return;
    }
    
    count++;
    if(count < speed)
    {
        return;
    }
    count = 0;
    
    

    clear();

    head += dir;
    for (auto it = snake_nodes.begin(); it != snake_nodes.end(); ++it) {
    if (it == snake_nodes.begin()) continue;

    if (head == *it) {
        end();
        break;
    }
    }
    if(!(head == food))
    {
        snake_nodes.pop_front();
    }
    else
    {
        generateFood();
        if(snake_nodes.size() % 2 == 0)
        {
            speed--;
            if(speed < 3) speed = 3;
            level++;
        }
    }
    if(head.getX() >= 9)
    {
        head.setX(1);
    }
    if(head.getX() <= 0)
    {
        head.setX(8);
    }
    if(head.getY() >= 29)
    {
        head.setY(1);
    }
    if(head.getY() <= 0)
    {
        head.setY(28);
    }
    snake_nodes.push_back(head);
    snake_draw();
    disp_level();

}

void Snake::snake_draw()
{
    for (const auto& node : snake_nodes) {
        setChar(node.getX(), node.getY(), '0');
    }
    setChar(food.getX(), food.getY(), '@');
}

void Snake::handleEvent(int ch) {
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
    if(ch == 'p')
    {
        paused = !paused;
    }
    if(ch == 'r')
    {
        end();
    }
    if(paused)
    {
        return;
    }
    if(ch == 'w' && dir.getX() != 1)
    {
        dir.setX(-1);
        dir.setY(0);
    }
    if(ch == 's' && dir.getX() != -1)
    {
        dir.setX(1);
        dir.setY(0);
    }
    if(ch == 'd' && dir.getY() != -1)
    {
        dir.setX(0);
        dir.setY(1);
    }
    if(ch == 'a' && dir.getY() != 1)
    {
        dir.setX(0);
        dir.setY(-1);
    }
}

void Snake::generateFood() {
    while (1)
    {
        food.setX(snake_nodes.front().getX() - dir.getX() + rand() % 5 - 1);
        food.setY(snake_nodes.front().getY() - dir.getY() + rand() % 5 - 1);
        if(food.getX() >= 8)
        {
            food.setX(1);
        }
        if(food.getX() <= 0)
        {
            food.setX(8);
        }
        if(food.getY() >= 28)
        {
            food.setY(1);
        }
        if(food.getY() <= 0)
        {
            food.setY(28);
        }
        bool ok = true;
        for (auto node : snake_nodes) {
            if(node == food) ok = false;
        }
        if(ok) break;
    }
}

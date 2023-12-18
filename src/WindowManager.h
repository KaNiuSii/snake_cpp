#ifndef W_WINDOWMANAGER_H
#define W_WINDOWMANAGER_H

#include <ncurses.h>
#include <vector>
#include "Layer.h"
#include "EventHandler.h"

class WindowManager {
private:
    std::vector<Layer> layers;
    bool running;

public:
    EventHandler * eventHandler = nullptr;

    WindowManager();
    ~WindowManager();

    void addLayer(const Layer& layer);
    void draw();
    void gameLoop();
    void stop();
};

#endif //W_WINDOWMANAGER_H

//
// Created by root on 12/12/23.
//

#ifndef W_EVENTHANDLER_H
#define W_EVENTHANDLER_H
#include "Moveable.h"
#include <memory>
#include <iostream>
class EventHandler {
private:
    std::vector<std::shared_ptr<Moveable>> objects;
public:
    int current;

    EventHandler() : current(1) {}  // Constructor to initialize `current`

    void handleEvents(int ch) {
        if (objects.empty()) {
            return;
        }
        
        if (ch == 't') {
            current = (current + 1) % objects.size();
        } else {
            objects[current]->handleEvent(ch);
        }
    }

    void addObject(std::shared_ptr<Moveable> obj) {
        objects.push_back(obj);
    }
};

#endif //W_EVENTHANDLER_H

#ifndef W_LAYER_H
#define W_LAYER_H

#include <vector>
#include <memory>
#include "Drawable.h"

class Layer {
private:
    std::vector<std::shared_ptr<Drawable>> objects;

public:
    void addObject(std::shared_ptr<Drawable> obj);
    void draw(WINDOW* win) const;
    void update() {
        for (auto& obj : objects) {
            obj->update();
        }
    }

};

#endif //W_LAYER_H

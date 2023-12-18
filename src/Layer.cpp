#include "Layer.h"

void Layer::addObject(std::shared_ptr<Drawable> obj) {
    objects.push_back(obj);
}

void Layer::draw(WINDOW* win) const {
    for (const auto& obj : objects) {
        obj->draw(win);
    }
}

#ifndef W_ADD_H
#define W_ADD_H

#include "Drawable.h"
#include "Moveable.h"

class Add : public Moveable{
public:
    Add();

    void start() override;
    void update() override {}
    void handleEvent(int ch) override;
};

#endif //W_ADD_H

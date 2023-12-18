#ifndef W_INSTRUCTION_H
#define W_INSTRUCTION_H

#include "Drawable.h"
#include "Moveable.h"

class Instruction : public Moveable{
public:
    Instruction();

    void start() override;
    void update() override {}
    void handleEvent(int ch) override;
};

#endif //W_INSTRUCTION_H

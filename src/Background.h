//
// Created by root on 12/11/23.
//

#ifndef W_BACKGROUND_H
#define W_BACKGROUND_H
#include "Drawable.h"
class Background : public Drawable {
public:
    Background();
    void start() override;
    void update() override {}
};
#endif //W_BACKGROUND_H

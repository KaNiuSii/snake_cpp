#include "WindowManager.h"
#include <iostream>
#include "Instruction.h"
#include "Background.h"
#include "Snake.h"
#include "Add.h"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));
    
    WindowManager wm;

    // Game object
    auto instruction = std::make_shared<Instruction>();
    auto snake = std::make_shared<Snake>();
    auto bg = std::make_shared<Background>();
    auto add = std::make_shared<Add>();

    //Start
    instruction->start();
    bg->start();
    snake->start();
    add->start();
    //Layers
    Layer layer1, layer2, layer3;
    layer2.addObject(instruction);
    layer2.addObject(add);
    layer1.addObject(snake);
    layer3.addObject(bg);
    wm.addLayer(layer3);
    wm.addLayer(layer2);
    wm.addLayer(layer1);

    //Event handler
    EventHandler eventHandler;
    eventHandler.addObject(instruction);
    eventHandler.addObject(snake);
    eventHandler.addObject(add);
    wm.eventHandler = &eventHandler;

    std::cout << "Initializing WindowManager..." << std::endl;
    wm.gameLoop();

    return 0;
}
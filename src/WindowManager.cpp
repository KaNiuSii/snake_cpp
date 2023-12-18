#include "WindowManager.h"
#include "Instruction.h"
#include <chrono>
#include <thread>

WindowManager::WindowManager() : running(true) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
}

WindowManager::~WindowManager() {
    endwin();
}

void WindowManager::addLayer(const Layer& layer) {
    layers.push_back(layer);
}

void WindowManager::draw() {
    clear();
    for (const auto& layer : layers) {
        layer.draw(stdscr);
    }
    wrefresh(stdscr);
}

void WindowManager::gameLoop() {
    using clock = std::chrono::high_resolution_clock;
    auto previousTime = clock::now();
    double lag = 0.0;
    const double msPerFrame = 1000.0 / 40.0; // 60 FPS

    while (running) {
        auto currentTime = clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - previousTime).count();
        previousTime = currentTime;
        lag += elapsedTime;

        int ch = getch();
        if (ch == KEY_EXIT) {
            running = false; // Exit the game loop
        }
        if (eventHandler != nullptr && ch != ERR)
        {
            eventHandler->handleEvents(ch);
        }
        while (lag >= msPerFrame) {
            // update(); // Update game logic here
            for (auto& layer : layers) {
                layer.update(); // Update each layer
            }
            lag -= msPerFrame;
        }

        draw(); // Draw all layers

        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long>(msPerFrame - lag)));
    }
}

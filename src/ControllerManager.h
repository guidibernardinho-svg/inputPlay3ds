#pragma once
#include <SDL2/SDL.h>

struct ControllerState {
    int lx, ly;
    int rx, ry;
    bool a, b, x, y;
};

class ControllerManager {
public:
    bool init();
    ControllerState poll();

private:
    SDL_GameController* controller = nullptr;
};

#include "ControllerManager.h"
#include <iostream>

bool ControllerManager::init() {
    if (SDL_Init(SDL_INIT_GAMECONTROLLER) < 0) {
        std::cout << "SDL erro\n";
        return false;
    }

    if (SDL_NumJoysticks() < 1) {
        std::cout << "Nenhum controle\n";
        return false;
    }

    controller = SDL_GameControllerOpen(0);
    return controller != nullptr;
}

ControllerState ControllerManager::poll() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {}

    ControllerState s;

    s.lx = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTX);
    s.ly = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_LEFTY);
    s.rx = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_RIGHTX);
    s.ry = SDL_GameControllerGetAxis(controller, SDL_CONTROLLER_AXIS_RIGHTY);

    s.a = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_A);
    s.b = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_B);
    s.x = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_X);
    s.y = SDL_GameControllerGetButton(controller, SDL_CONTROLLER_BUTTON_Y);

    return s;
}

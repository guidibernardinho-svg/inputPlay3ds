#include "ControllerManager.h"
#include "NetworkClient.h"
#include <iostream>

int main() {
    ControllerManager controller;
    NetworkClient net("192.168.0.10", 4950); // IP do 3DS

    if (!controller.init()) {
        std::cout << "Erro ao iniciar controle\n";
        return 1;
    }

    while (true) {
        ControllerState state = controller.poll();

        net.sendState(state);

        SDL_Delay(16); // ~60 FPS
    }

    return 0;
}

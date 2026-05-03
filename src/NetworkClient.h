#pragma once
#include <string>
#include "ControllerManager.h"

class NetworkClient {
public:
    NetworkClient(const std::string& ip, int port);
    void sendState(const ControllerState& state);

private:
    int sock;
    struct sockaddr_in serverAddr;
};

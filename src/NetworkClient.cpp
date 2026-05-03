#include "NetworkClient.h"
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

NetworkClient::NetworkClient(const std::string& ip, int port) {
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &serverAddr.sin_addr);
}

void NetworkClient::sendState(const ControllerState& s) {
    sendto(sock, &s, sizeof(s), 0,
           (struct sockaddr*)&serverAddr, sizeof(serverAddr));
}

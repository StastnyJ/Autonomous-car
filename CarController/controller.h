#pragma once

struct StickPosition {
    float xCoord;
    float yCoord;
};

struct Controller {
    int isConnected;
    int battery;
    struct StickPosition leftStick;
    struct StickPosition rightStick;
};

void initController(char* address);
struct Controller getController();
#include <Ps3Controller.h>
#pragma once

struct StickPosition {
    float xCoord;
    float yCoord;
};

struct Controller {
    int isConnected;
    int battery;
    StickPosition leftStick;
    StickPosition rightStick;
};

struct Controller controller;

void initController(char* address);

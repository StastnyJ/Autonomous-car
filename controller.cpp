#include "controller.h"

#include <Ps3Controller.h>

struct Controller controller;

void notify() {
    if (abs(Ps3.event.analog_changed.stick.lx) +
            abs(Ps3.event.analog_changed.stick.ly) >
        2) {
        controller.leftStick.xCoord =
            ((float)Ps3.data.analog.stick.lx) / 128.0f;
        controller.leftStick.yCoord =
            ((float)Ps3.data.analog.stick.ly) / -128.0f;
    }
    if (abs(Ps3.event.analog_changed.stick.rx) +
            abs(Ps3.event.analog_changed.stick.ry) >
        2) {
        controller.rightStick.xCoord =
            ((float)Ps3.data.analog.stick.rx) / 128.0f;
        controller.rightStick.yCoord =
            ((float)Ps3.data.analog.stick.ry) / -128.0f;
    }
    controller.battery = Ps3.data.status.battery;
}

void onConnect() {
    controller.isConnected = 1;
    Ps3.setPlayer(1);
}

struct Controller getController() {
    return controller;
}

void initController(char* address) {
    controller.isConnected = 0;
    Ps3.attach(notify);
    Ps3.attachOnConnect(onConnect);
    Ps3.begin(address);
}

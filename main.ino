#include "controller.h"

void setup() {
    Serial.begin(9600);
    initController("00:1e:3d:4a:36:13");
    Serial.println("Ready.");
}

void loop() {
    if (controller.isConnected) {
        Serial.printf("LEFT STICK: %3f, %3f\n", controller.leftStick.xCoord,
                      controller.leftStick.yCoord);
        Serial.printf("RIGHT STICK: %3f, %3f\n", controller.rightStick.xCoord,
                      controller.rightStick.yCoord);
    } else {
        Serial.println("Controller disconnected");
    }
    delay(1000);
}
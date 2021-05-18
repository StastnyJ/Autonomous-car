#include "carMotionController.h"
#include "controller.h"
#include "pinsStructure.h"

struct CarMotionController car;

void setup() {
    car = createCar(MOTOR_LEFT_TOP_FORWARDS_PIN, MOTOR_LEFT_TOP_BACKWARDS_PIN,
                    MOTOR_RIGHT_TOP_FORWARDS_PIN, MOTOR_RIGHT_TOP_BACKWARDS_PIN,
                    MOTOR_LEFT_BACK_FORWARDS_PIN, MOTOR_LEFT_BACK_BACKWARDS_PIN,
                    MOTOR_RIGHT_BACK_FORWARDS_PIN,
                    MOTOR_RIGHT_BACK_BACKWARDS_PIN);
    initCar(car);

    pinMode(CONTROLLER_CONNECTED_LED_INDICATOR, OUTPUT);

    Serial.begin(9600);
    initController("00:1e:3d:4a:36:13");
    Serial.println("Ready.");
}

void loop() {
    if (getController().isConnected) {
        digitalWrite(CONTROLLER_CONNECTED_LED_INDICATOR, HIGH);
        if (getController().leftStick.yCoord > 0.5f) {
            carForward(car);
        } else if (getController().leftStick.yCoord < -0.5f) {
            carBackward(car);
        } else if (getController().leftStick.xCoord > 0.5f) {
            carRight(car);
        } else if (getController().leftStick.xCoord < -0.5f) {
            carLeft(car);
        } else {
            carIdle(car);
        }
    } else {
        digitalWrite(CONTROLLER_CONNECTED_LED_INDICATOR, LOW);
    }
}
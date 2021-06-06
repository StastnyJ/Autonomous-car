#include "motor.h"

#include <Arduino.h>

struct Motor createMotor(int forwardPin, int backwardPin, int controlPin,
                         int speedPin) {
    struct Motor res;
    res.forwardPin = forwardPin;
    res.backwardPin = backwardPin;
    res.controlPin = controlPin;
    res.speedPin = speedPin;

    return res;
}

void initMotor(struct Motor motor) {
    pinMode(motor.forwardPin, OUTPUT);
    pinMode(motor.backwardPin, OUTPUT);
    pinMode(motor.controlPin, INPUT);
    pinMode(motor.speedPin, INPUT);
}

// void motorForward(struct Motor motor) {
//     digitalWrite(motor.forwardPin, HIGH);
//     digitalWrite(motor.backwardPin, LOW);
// }

// void motorBackward(struct Motor motor) {
//     digitalWrite(motor.forwardPin, LOW);
//     digitalWrite(motor.backwardPin, HIGH);
// }

// void breakMotor(struct Motor motor) {
//     digitalWrite(motor.forwardPin, HIGH);
//     digitalWrite(motor.backwardPin, HIGH);
// }

// void motorIdle(struct Motor motor) {
//     digitalWrite(motor.forwardPin, LOW);
//     digitalWrite(motor.backwardPin, LOW);
// }
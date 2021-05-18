#include "motor.h"

#include <Arduino.h>

struct Motor createMotor(int forwardPin, int backwardPin) {
    struct Motor res;
    res.forwardPin = forwardPin;
    res.backwardPin = backwardPin;
    return res;
}

void initMotor(struct Motor motor) {
    pinMode(motor.forwardPin, OUTPUT);
    pinMode(motor.backwardPin, OUTPUT);
}

void motorForward(struct Motor motor) {
    digitalWrite(motor.forwardPin, HIGH);
    digitalWrite(motor.backwardPin, LOW);
    Serial.printf("%d H\n%d L\n", motor.forwardPin, motor.backwardPin);
}

void motorBackward(struct Motor motor) {
    digitalWrite(motor.forwardPin, LOW);
    digitalWrite(motor.backwardPin, HIGH);
    Serial.printf("%d H\n%d L\n", motor.backwardPin, motor.forwardPin);
}

void breakMotor(struct Motor motor) {
    digitalWrite(motor.forwardPin, HIGH);
    digitalWrite(motor.backwardPin, HIGH);
    Serial.printf("%d H\n%d H\n", motor.forwardPin, motor.backwardPin);
}

void motorIdle(struct Motor motor) {
    digitalWrite(motor.forwardPin, LOW);
    digitalWrite(motor.backwardPin, LOW);
    Serial.printf("%d L\n%d L\n", motor.forwardPin, motor.backwardPin);
}
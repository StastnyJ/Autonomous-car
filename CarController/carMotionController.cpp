#include "carMotionController.h"

#include "motor.h"

struct CarMotionController createCar(
    int leftTopForwardPin, int leftTopBackwardPin, int rightTopForwardPin,
    int rightTopBackwardPin, int leftBackForwardPin, int leftBackBackwardPin,
    int rightBackForwardPin, int rightBackBackwardPin) {
    struct CarMotionController res;
    res.leftTop = createMotor(leftTopForwardPin, leftTopBackwardPin);
    res.rightTop = createMotor(rightTopForwardPin, rightTopBackwardPin);
    res.leftBack = createMotor(leftBackForwardPin, leftBackBackwardPin);
    res.rightBack = createMotor(rightBackForwardPin, rightBackBackwardPin);
    return res;
}

void initCar(struct CarMotionController car) {
    initMotor(car.leftTop);
    initMotor(car.rightTop);
    initMotor(car.leftBack);
    initMotor(car.rightBack);
}

void carForward(struct CarMotionController car) {
    motorForward(car.leftTop);
    motorForward(car.rightTop);
    motorForward(car.leftBack);
    motorForward(car.rightBack);
}
void carLeft(struct CarMotionController car) {
    motorForward(car.leftTop);
    motorBackward(car.rightTop);
    motorBackward(car.leftBack);
    motorForward(car.rightBack);
}

void carRight(struct CarMotionController car) {
    motorBackward(car.leftTop);
    motorForward(car.rightTop);
    motorForward(car.leftBack);
    motorBackward(car.rightBack);
}

void carBackward(struct CarMotionController car) {
    motorBackward(car.leftTop);
    motorBackward(car.rightTop);
    motorBackward(car.leftBack);
    motorBackward(car.rightBack);
}

void breakCar(struct CarMotionController car) {
    breakMotor(car.leftTop);
    breakMotor(car.rightTop);
    breakMotor(car.leftBack);
    breakMotor(car.rightBack);
}
void carIdle(struct CarMotionController car) {
    motorIdle(car.leftTop);
    motorIdle(car.rightTop);
    motorIdle(car.leftBack);
    motorIdle(car.rightBack);
}

#include "motor.h"
#pragma once

struct CarMotionController {
    struct Motor leftTop;
    struct Motor rightTop;
    struct Motor leftBack;
    struct Motor rightBack;
};

struct CarMotionController createCar(
    int leftTopForwardPin, int leftTopBackwardPin, int rightTopForwardPin,
    int rightTopBackwardPin, int leftBackForwardPin, int leftBackBackwardPin,
    int rightBackForwardPin, int rightBackBackwardPin);
void initCar(struct CarMotionController car);

void carForward(struct CarMotionController car);
void carLeft(struct CarMotionController car);
void carRight(struct CarMotionController car);
void carBackward(struct CarMotionController car);

void breakCar(struct CarMotionController car);
void carIdle(struct CarMotionController car);

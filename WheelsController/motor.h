// #ifndef MotorStruct
// #define MotorStruct
struct Motor {
    int forwardPin, backwardPin, controlPin, speedPin;
};
// #endif

struct Motor createMotor(int forwardPin, int backwardPin, int controlPin,
                         int speedPin);
void initMotor(struct Motor motor);

void motorForward(struct Motor motor);
void motorBackward(struct Motor motor);
void breakMotor(struct Motor motor);
void motorIdle(struct Motor motor);

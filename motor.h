#ifndef MotorStruct
#define MotorStruct
struct Motor {
    int forwardPin, backwardPin;
};
#endif /* !FILE_FOO_SEEN */

struct Motor createMotor(int forwardPin, int backwardPin);
void initMotor(struct Motor motor);

void motorForward(struct Motor motor);
void motorBackward(struct Motor motor);
void breakMotor(struct Motor motor);
void motorIdle(struct Motor motor);

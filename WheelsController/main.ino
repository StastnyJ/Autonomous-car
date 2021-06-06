#include "motor.h"
#include "pins.h"

struct Motor motor0;
// TODO other 3 motors

void setup() {
    Serial.begin(9600);
    motor0 = createMotor(M0_FORWARD, M0_BACKWARD, A0, A1);
    initMotor(motor0);
}

void loop() {
    int A0value = analogRead(A0);
    char buffer[64];
    sprintf(buffer, "%d\n", A0value);
    Serial.print(buffer);
}
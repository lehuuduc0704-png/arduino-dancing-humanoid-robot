#ifndef SERVO_CONTROLLER_H
#define SERVO_CONTROLLER_H

#include <Arduino.h>
#include <Servo.h>

class ServoController
{
private:

    Servo servo;

    int pin;

    int currentAngle;

    int minAngle;

    int maxAngle;

    int centerAngle;

public:

    ServoController(
        int pin,
        int minAngle,
        int maxAngle,
        int centerAngle
    );

    void begin();

    void moveTo(int angle);

    void moveSmooth(int angle, int speed = 10);

    void center();

    int getAngle();
};

#endif

#ifndef SERVOCONTROLLER_H
#define SERVOCONTROLLER_H

#include <Arduino.h>
#include <Servo.h>

class ServoController
{
private:

    Servo servo;

public:

    byte pin;

    int minAngle;

    int maxAngle;

    int currentAngle;

    bool attached;

public:

    ServoController(
        byte pin,
        int minAngle,
        int maxAngle,
        int startAngle
    );

    void begin();

    void move(int angle);

    void moveSmooth(int angle);

    void center();
};

#endif

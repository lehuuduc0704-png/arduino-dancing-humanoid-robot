#ifndef SERVO_CONTROLLER_H
#define SERVO_CONTROLLER_H

#include <Servo.h>

class ServoController
{
private:
    Servo servo;

public:

    void attach(int pin);

    void write(int angle);

    void moveSmooth(int from,int to,int speed);

};

#endif

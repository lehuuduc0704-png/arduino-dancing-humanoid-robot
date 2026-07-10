#include "ServoController.h"

void ServoController::attach(int pin)
{
    servo.attach(pin);
}

void ServoController::write(int angle)
{
    servo.write(angle);
}

void ServoController::moveSmooth(int from,int to,int speed)
{
    if(from<to)
    {
        for(int i=from;i<=to;i++)
        {
            servo.write(i);
            delay(speed);
        }
    }
    else
    {
        for(int i=from;i>=to;i--)
        {
            servo.write(i);
            delay(speed);
        }
    }
}

#include "ServoController.h"

ServoController::ServoController(
    int pin,
    int minAngle,
    int maxAngle,
    int centerAngle)
{
    this->pin = pin;
    this->minAngle = minAngle;
    this->maxAngle = maxAngle;
    this->centerAngle = centerAngle;

    currentAngle = centerAngle;
}
void ServoController::begin()
{
    servo.attach(pin);

    servo.write(centerAngle);

    currentAngle = centerAngle;
}
void ServoController::moveTo(int angle)
{
    // Giới hạn góc
    if (angle < minAngle)
    {
        angle = minAngle;
    }

    if (angle > maxAngle)
    {
        angle = maxAngle;
    }
    servo.write(angle);
    currentAngle = angle;
}
void ServoController::moveSmooth(int angle, int speed)
{
    if (angle < minAngle)
    {
        angle = minAngle;
    }

    if (angle > maxAngle)
    {
        angle = maxAngle;
    }
    if (currentAngle < angle)
    {
        for (int i = currentAngle; i <= angle; i++)
        {
            servo.write(i);
            delay(speed);
        }
    }
    else
    {
        for (int i = currentAngle; i >= angle; i--)
        {
            servo.write(i);
            delay(speed);
        }
    }

    currentAngle = angle;
}
void ServoController::center()
{
    moveSmooth(centerAngle);
}

int ServoController::getAngle()
{
    return currentAngle;
}

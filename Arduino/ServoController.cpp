#include "ServoController.h"

#include "Config.h"

ServoController::ServoController(
    byte pin,
    int minAngle,
    int maxAngle,
    int centerAngle)
{
    this->pin = pin;

    this->minAngle = minAngle;

    this->maxAngle = maxAngle;

    this->centerAngle = centerAngle;

    this->currentAngle = centerAngle;

    this->attached = false;
}

void ServoController::begin()
{
    if (attached)
    {
        return;
    }

    servo.attach(pin);

    servo.write(centerAngle);

    currentAngle = centerAngle;

    attached = true;

    delay(300);
}

void ServoController::move(int angle)
{
    angle = constrain(angle, minAngle, maxAngle);

    servo.write(angle);

    currentAngle = angle;
}

void ServoController::moveSmooth(int angle)
{
    angle = constrain(angle, minAngle, maxAngle);

    if (angle == currentAngle)
    {
        return;
    }

    int step = (angle > currentAngle) ? 1 : -1;

    for (int pos = currentAngle; pos != angle; pos += step)
    {
        servo.write(pos);

        delay(SERVO_DELAY);
    }

    servo.write(angle);

    currentAngle = angle;
}

void ServoController::center()
{
    moveSmooth(centerAngle);
}

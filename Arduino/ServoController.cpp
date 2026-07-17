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

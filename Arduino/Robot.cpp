#include "Robot.h"

Robot::Robot()

    : head(
        HEAD_PIN,
        HEAD_LEFT,
        HEAD_RIGHT,
        HEAD_CENTER),

      leftArm(
        LEFT_ARM_PIN,
        LEFT_ARM_UP,
        LEFT_ARM_DOWN,
        LEFT_ARM_CENTER),

      rightArm(
        RIGHT_ARM_PIN,
        RIGHT_ARM_DOWN,
        RIGHT_ARM_UP,
        RIGHT_ARM_CENTER),

      leftWing(
        LEFT_WING_PIN,
        LEFT_WING_CLOSE,
        LEFT_WING_OPEN,
        LEFT_WING_CENTER),

      rightWing(
        RIGHT_WING_PIN,
        RIGHT_WING_OPEN,
        RIGHT_WING_CLOSE,
        RIGHT_WING_CENTER)

{

}
void Robot::begin()
{
    head.begin();

    leftArm.begin();

    rightArm.begin();

    leftWing.begin();

    rightWing.begin();

    startup();
}

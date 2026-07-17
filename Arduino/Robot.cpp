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

    servos[0] = &head;
    servos[1] = &leftArm;
    servos[2] = &rightArm;
    servos[3] = &leftWing;
    servos[4] = &rightWing;

}
void Robot::begin()
{
    for (int i = 0; i < 5; i++)
    {
        servos[i]->begin();
    }

    pinMode(CHEST_LED_PIN, OUTPUT);

    pinMode(BUZZER_PIN, OUTPUT);

    pinMode(SOUND_PIN, INPUT);

    startup();
}
void Robot::startup()
{
    digitalWrite(CHEST_LED_PIN, HIGH);

    tone(BUZZER_PIN, 1000, 150);

    head.center();

    leftArm.center();
    rightArm.center();

    leftWing.center();
    rightWing.center();

    delay(300);

    leftWing.moveSmooth(LEFT_WING_OPEN);

    rightWing.moveSmooth(RIGHT_WING_OPEN);

    delay(300);

    leftWing.moveSmooth(LEFT_WING_CLOSE);

    rightWing.moveSmooth(RIGHT_WING_CLOSE);

    delay(300);

    head.moveSmooth(HEAD_LEFT);

    head.moveSmooth(HEAD_RIGHT);

    head.center();
}

#include "Robot.h"

//====================================================
// Constructor
//====================================================

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

//====================================================
// Initialization
//====================================================

void Robot::initDevices()
{
    pinMode(CHEST_LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(SOUND_PIN, INPUT);

    digitalWrite(CHEST_LED_PIN, LOW);
}

void Robot::begin()
{
    for (int i = 0; i < 5; i++)
    {
        servos[i]->begin();
    }

    initDevices();

    startup();
}

//====================================================
// Startup
//====================================================

void Robot::startup()
{
    digitalWrite(CHEST_LED_PIN, HIGH);

    centerAll();

    delay(300);

    openWings();

    delay(300);

    closeWings();

    delay(300);

    lookLeft();

    delay(200);

    lookRight();

    delay(200);

    lookCenter();

    delay(300);
}

//====================================================
// Head Motion
//====================================================

void Robot::lookLeft()
{
    head.moveSmooth(HEAD_LEFT);
}

void Robot::lookRight()
{
    head.moveSmooth(HEAD_RIGHT);
}

void Robot::lookCenter()
{
    head.center();
}

//====================================================
// Wing Motion
//====================================================

void Robot::openWings()
{
    leftWing.moveSmooth(LEFT_WING_OPEN);

    rightWing.moveSmooth(RIGHT_WING_OPEN);
}

void Robot::closeWings()
{
    leftWing.moveSmooth(LEFT_WING_CLOSE);

    rightWing.moveSmooth(RIGHT_WING_CLOSE);
}

//====================================================
// Arm Motion
//====================================================

void Robot::raiseArms()
{
    leftArm.moveSmooth(LEFT_ARM_UP);

    rightArm.moveSmooth(RIGHT_ARM_UP);
}

void Robot::lowerArms()
{
    leftArm.moveSmooth(LEFT_ARM_DOWN);

    rightArm.moveSmooth(RIGHT_ARM_DOWN);
}

//====================================================
// Reset Position
//====================================================

void Robot::centerAll()
{
    head.center();

    leftArm.center();

    rightArm.center();

    leftWing.center();

    rightWing.center();
}

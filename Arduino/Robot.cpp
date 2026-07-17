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
    lastSoundTime = 0;
}

//====================================================
// Initialization
//====================================================
bool Robot::soundDetected()
{
    if (digitalRead(SOUND_PIN) != SOUND_TRIGGER)
    {
        return false;
    }

    if (millis() - lastSoundTime < 2000)
    {
        return false;
    }

    lastSoundTime = millis();

    return true;
}
void Robot::initDevices()
{
    pinMode(SOUND_PIN, INPUT);

    effects.begin();
}

void Robot::begin()
{
    for (byte i = 0; i < 5; i++)
    {
        servos[i]->begin();
    }

    initDevices();

    startup();
}
//====================================================
// Head Actions
//====================================================

void Robot::lookLeft()
{
    head.moveSmooth(HEAD_LEFT);

    delay(ACTION_DELAY);
}

void Robot::lookRight()
{
    head.moveSmooth(HEAD_RIGHT);

    delay(ACTION_DELAY);
}

void Robot::lookCenter()
{
    head.center();

    delay(ACTION_DELAY);
}

void Robot::nodHead()
{
    head.moveSmooth(HEAD_DOWN);

    delay(ACTION_DELAY);

    head.moveSmooth(HEAD_UP);

    delay(ACTION_DELAY);

    head.center();

    delay(ACTION_DELAY);
}

void Robot::shakeHead()
{
    lookLeft();

    lookRight();

    lookLeft();

    lookRight();

    lookCenter();
}
//====================================================
// Arm Actions
//====================================================

void Robot::raiseArms()
{
    leftArm.moveSmooth(LEFT_ARM_UP);

    rightArm.moveSmooth(RIGHT_ARM_UP);

    delay(ACTION_DELAY);
}

void Robot::lowerArms()
{
    leftArm.moveSmooth(LEFT_ARM_DOWN);

    rightArm.moveSmooth(RIGHT_ARM_DOWN);

    delay(ACTION_DELAY);
}

void Robot::waveLeftHand()
{
    raiseArms();

    for (byte i = 0; i < 2; i++)
    {
        leftArm.moveSmooth(LEFT_ARM_CENTER);

        delay(150);

        leftArm.moveSmooth(LEFT_ARM_UP);

        delay(150);
    }

    leftArm.center();
}

void Robot::waveRightHand()
{
    raiseArms();

    for (byte i = 0; i < 2; i++)
    {
        rightArm.moveSmooth(RIGHT_ARM_CENTER);

        delay(150);

        rightArm.moveSmooth(RIGHT_ARM_UP);

        delay(150);
    }

    rightArm.center();
}

void Robot::waveBothHands()
{
    raiseArms();

    for (byte i = 0; i < 2; i++)
    {
        leftArm.moveSmooth(LEFT_ARM_CENTER);
        rightArm.moveSmooth(RIGHT_ARM_CENTER);

        delay(150);

        leftArm.moveSmooth(LEFT_ARM_UP);
        rightArm.moveSmooth(RIGHT_ARM_UP);

        delay(150);
    }

    raiseArms();
}
//====================================================
// Wing Actions
//====================================================

void Robot::openWings()
{
    leftWing.moveSmooth(LEFT_WING_OPEN);

    rightWing.moveSmooth(RIGHT_WING_OPEN);

    delay(ACTION_DELAY);
}

void Robot::closeWings()
{
    leftWing.moveSmooth(LEFT_WING_CLOSE);

    rightWing.moveSmooth(RIGHT_WING_CLOSE);

    delay(ACTION_DELAY);
}

void Robot::flapWings()
{
    for (byte i = 0; i < 3; i++)
    {
        openWings();

        closeWings();
    }

    closeWings();
}
//====================================================
// Full Body Actions
//====================================================

void Robot::centerAll()
{
    head.center();

    leftArm.center();

    rightArm.center();

    leftWing.center();

    rightWing.center();

    delay(ACTION_DELAY);
}

void Robot::readyPose()
{
    centerAll();

    closeWings();

    lowerArms();
}

void Robot::celebrate()
{
    for (byte i = 0; i < 3; i++)
    {
        waveBothHands();

        flapWings();

        nodHead();
    }

    centerAll();
}
//====================================================
// Startup
//====================================================

void Robot::startup()
{
    effects.ledOn();

    readyPose();

    delay(500);

    openWings();

    delay(300);

    closeWings();

    delay(300);

    shakeHead();

    centerAll();
}
//====================================================
// Behavior
//====================================================

void Robot::idle()
{
    centerAll();

    effects.ledOff();
}
void Robot::greeting()
{
    effects.ledOn();

    waveRightHand();

    nodHead();

    waveRightHand();

    centerAll();
}
//====================================================
// Dance
//====================================================

void Robot::dance1()
{
    effects.ledOn();

    readyPose();

    for(byte i = 0; i < 3; i++)
    {
        flapWings();

        waveBothHands();

        nodHead();
    }

    centerAll();
}
void Robot::dance2()
{
    effects.ledOn();

    readyPose();

    for(byte i = 0; i < 2; i++)
    {
        shakeHead();

        waveLeftHand();

        waveRightHand();

        flapWings();
    }

    centerAll();
}
void Robot::dance3()
{
    effects.ledOn();

    readyPose();

    for(byte i = 0; i < 3; i++)
    {
        raiseArms();

        openWings();

        nodHead();

        closeWings();

        lowerArms();

        shakeHead();
    }

    centerAll();
}
void Robot::dance4()
{
    effects.ledOn();

    readyPose();

    for(byte i = 0; i < 4; i++)
    {
        lookLeft();

        raiseArms();

        lookRight();

        lowerArms();

        openWings();

        closeWings();
    }

    centerAll();
}
void Robot::dance5()
{
    effects.ledOn();

    readyPose();

    for(byte i = 0; i < 5; i++)
    {
        waveBothHands();

        flapWings();

        shakeHead();
    }

    centerAll();
}
void Robot::dance6()
{
    effects.ledOn();

    readyPose();

    for(byte i = 0; i < 3; i++)
    {
        celebrate();

        nodHead();

        celebrate();
    }

    centerAll();
}
void Robot::dance7()
{
    effects.ledOn();

    readyPose();

    for(byte i = 0; i < 6; i++)
    {
        openWings();

        closeWings();
    }

    centerAll();
}
void Robot::dance8()
{
    effects.ledOn();

    readyPose();

    for(byte i = 0; i < 4; i++)
    {
        waveRightHand();

        nodHead();

        waveLeftHand();

        nodHead();
    }

    centerAll();
}
void Robot::dance9()
{
    effects.ledOn();

    readyPose();

    for(byte i = 0; i < 6; i++)
    {
        flapWings();

        nodHead();
    }

    centerAll();
}
void Robot::dance10()
{
    effects.ledOn();

    readyPose();

    for(byte i = 0; i < 5; i++)
    {
        waveBothHands();

        flapWings();

        shakeHead();

        celebrate();
    }

    centerAll();

    effects.ledOff();
}
void Robot::randomDance()
{
    switch(random(DANCE_COUNT))
    {
        case 0: dance1(); break;
        case 1: dance2(); break;
        case 2: dance3(); break;
        case 3: dance4(); break;
        case 4: dance5(); break;
        case 5: dance6(); break;
        case 6: dance7(); break;
        case 7: dance8(); break;
        case 8: dance9(); break;
        case 9: dance10(); break;

        default:
            dance1();
            break;
    }
}
//====================================================
// Update
//====================================================

void Robot::update()
{
    if(soundDetected())
    {
        randomDance();
    }
}

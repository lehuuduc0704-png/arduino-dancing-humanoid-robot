#ifndef ROBOT_H
#define ROBOT_H

#include <Arduino.h>

#include "Config.h"
#include "ServoController.h"
#include "Effects.h"

class Robot
{
private:

    //========================
    // Robot Parts
    //========================

    ServoController head;

    ServoController leftArm;

    ServoController rightArm;

    ServoController leftWing;

    ServoController rightWing;

    //========================
    // Devices
    //========================

    Effects effects;

public:

    Robot();

    void begin();

    void update();

    void startup();

    void greeting();

    void idle();

    void dance1();

    void dance2();

    void dance3();

    void randomDance();

    void openWings();

    void closeWings();

    void raiseArms();

    void lowerArms();

    void centerAll();
private:
    ServoController head;
    ServoController leftArm;
    ServoController rightArm;
    ServoController leftWing;
    ServoController rightWing;
    ServoController* servos[5];
    Effects effects;
};

#endif

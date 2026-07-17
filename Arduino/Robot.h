#ifndef ROBOT_H
#define ROBOT_H

#include <Arduino.h>

#include "ServoController.h"
#include "Config.h"
#include "Effects.h"

class Robot
{
private:

    ServoController head;
    ServoController leftArm;
    ServoController rightArm;
    ServoController leftWing;
    ServoController rightWing;

    Effects effect;

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
};

#endif

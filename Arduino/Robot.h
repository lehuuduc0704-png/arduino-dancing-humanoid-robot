#ifndef ROBOT_H
#define ROBOT_H

#include <Arduino.h>

#include "Config.h"
#include "ServoController.h"
#include "Effects.h"

class Robot
{
private:

    //====================================================
    // Robot Parts
    //====================================================

    ServoController head;
    ServoController leftArm;
    ServoController rightArm;
    ServoController leftWing;
    ServoController rightWing;

    // Danh sách tất cả servo
    ServoController* servos[5];

    //====================================================
    // Devices
    //====================================================

    Effects effects;

    //====================================================
    // Private Functions
    //====================================================

    void initDevices();

public:

    //====================================================
    // Constructor
    //====================================================

    Robot();

    //====================================================
    // Initialization
    //====================================================

    void begin();

    void update();

    //====================================================
    // Startup
    //====================================================

    void startup();

    //====================================================
    // Head Motion
    //====================================================

    void lookLeft();

    void lookRight();

    void lookCenter();

    //====================================================
    // Wing Motion
    //====================================================

    void openWings();

    void closeWings();

    //====================================================
    // Arm Motion
    //====================================================

    void raiseArms();

    void lowerArms();

    //====================================================
    // Robot Motion
    //====================================================

    void centerAll();

    //====================================================
    // Behaviors
    //====================================================

    void greeting();

    void idle();

    //====================================================
    // Dance
    //====================================================

    void dance1();

    void dance2();

    void dance3();

    void randomDance();
};

#endif

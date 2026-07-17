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

    // Danh sách tất cả Servo
    ServoController* servos[5];

    //====================================================
    // Devices
    //====================================================

    Effects effects;

    //====================================================
    // Private Functions
    //====================================================

    unsigned long lastSoundTime;

    void initDevices();

    bool soundDetected();
    
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
    // Actions
    //====================================================

    //--------------- Head ----------------

    void lookLeft();
    void lookRight();
    void lookCenter();

    void nodHead();
    void shakeHead();

    //--------------- Arms ----------------

    void raiseArms();
    void lowerArms();

    void waveLeftHand();
    void waveRightHand();
    void waveBothHands();

    //--------------- Wings ----------------

    void openWings();
    void closeWings();

    void flapWings();

    //--------------- Full Body ----------------

    void readyPose();
    void celebrate();
    void centerAll();

    //====================================================
    // Behavior
    //====================================================

    void idle();
    void greeting();

    //====================================================
    // Dance
    //====================================================

    void dance1();
    void dance2();
    void dance3();
    void dance4();
    void dance5();
    void dance6();
    void dance7();
    void dance8();
    void dance9();
    void dance10();
    void randomDance();
};

#endif

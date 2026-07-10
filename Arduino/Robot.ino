/*
===========================================
 Arduino Dancing Humanoid Robot
 Author : Le Huu Duc
 Version: 1.0
===========================================
*/
#include "Robot.h"

Robot robot;

void setup()
{
    robot.begin();
}

void loop()
{
    robot.update();
}

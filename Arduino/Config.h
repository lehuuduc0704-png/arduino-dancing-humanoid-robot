#ifndef CONFIG_H
#define CONFIG_H

//====================================================
// Servo Pins
//====================================================

#define HEAD_PIN            3

#define LEFT_ARM_PIN        5
#define RIGHT_ARM_PIN       6

#define LEFT_WING_PIN       9
#define RIGHT_WING_PIN      10

//====================================================
// Devices
//====================================================

#define SOUND_PIN           2
#define CHEST_LED_PIN       11

//====================================================
// Servo Limits
//====================================================

//--------------- Head ----------------

#define HEAD_LEFT           40
#define HEAD_CENTER         90
#define HEAD_RIGHT          140

#define HEAD_UP             70
#define HEAD_DOWN           110

//--------------- Left Arm ----------------

#define LEFT_ARM_UP         20
#define LEFT_ARM_CENTER     90
#define LEFT_ARM_DOWN       160

//--------------- Right Arm ----------------

#define RIGHT_ARM_UP        160
#define RIGHT_ARM_CENTER    90
#define RIGHT_ARM_DOWN      20

//--------------- Left Wing ----------------

#define LEFT_WING_CLOSE     20
#define LEFT_WING_CENTER    55
#define LEFT_WING_OPEN      90

//--------------- Right Wing ----------------

#define RIGHT_WING_CLOSE    160
#define RIGHT_WING_CENTER   125
#define RIGHT_WING_OPEN     90

//====================================================
// Motion
//====================================================

#define SERVO_SPEED         10
#define SERVO_DELAY         15

#define ACTION_DELAY        200

//====================================================
// Sound Sensor
//====================================================

#define SOUND_TRIGGER       HIGH

//====================================================
// Dance
//====================================================

#define DANCE_COUNT         10

#endif

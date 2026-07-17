#ifndef CONFIG_H
#define CONFIG_H

//====================================================
// Pin Configuration
//====================================================

// Servo Pins
#define HEAD_PIN            3
#define LEFT_ARM_PIN        5
#define RIGHT_ARM_PIN       6
#define LEFT_WING_PIN       9
#define RIGHT_WING_PIN      10

// Devices
#define SOUND_PIN           2
#define BUZZER_PIN          8
#define CHEST_LED_PIN       11

//====================================================
// Head Positions
//====================================================

#define HEAD_LEFT           60
#define HEAD_CENTER         90
#define HEAD_RIGHT          120

//====================================================
// Left Arm Positions
//====================================================

#define LEFT_ARM_UP         30
#define LEFT_ARM_CENTER     90
#define LEFT_ARM_DOWN       150

//====================================================
// Right Arm Positions
//====================================================

#define RIGHT_ARM_UP        150
#define RIGHT_ARM_CENTER    90
#define RIGHT_ARM_DOWN      30

//====================================================
// Left Wing Positions
//====================================================

#define LEFT_WING_CLOSE     20
#define LEFT_WING_CENTER    55
#define LEFT_WING_OPEN      90

//====================================================
// Right Wing Positions
//====================================================

#define RIGHT_WING_CLOSE    160
#define RIGHT_WING_CENTER   125
#define RIGHT_WING_OPEN     90

//====================================================
// Sound Sensor
//====================================================

#define SOUND_THRESHOLD     500

//====================================================
// Motion
//====================================================

#define DEFAULT_SPEED       8

#endif

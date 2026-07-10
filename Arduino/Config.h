#ifndef CONFIG_H
#define CONFIG_H

//========================
// Servo Pins
//========================

const byte HEAD_PIN = 3;
const byte LEFT_ARM_PIN = 5;
const byte RIGHT_ARM_PIN = 6;
const byte LEFT_WING_PIN = 9;
const byte RIGHT_WING_PIN = 10;

//========================
// Devices
//========================

const byte SOUND_PIN = 2;
const byte BUZZER_PIN = 8;
const byte CHEST_LED_PIN = 11;

//========================
// Default Position
//========================

const int HEAD_CENTER = 90;

const int LEFT_ARM_CENTER = 90;
const int RIGHT_ARM_CENTER = 90;

const int LEFT_WING_CLOSE = 20;
const int RIGHT_WING_CLOSE = 160;

const int LEFT_WING_OPEN = 90;
const int RIGHT_WING_OPEN = 90;

#endif

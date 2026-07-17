#include "Effects.h"

Effects::Effects()
{
}

void Effects::begin()
{
    pinMode(CHEST_LED_PIN, OUTPUT);

    digitalWrite(CHEST_LED_PIN, LOW);
}

void Effects::ledOn()
{
    digitalWrite(CHEST_LED_PIN, HIGH);
}

void Effects::ledOff()
{
    digitalWrite(CHEST_LED_PIN, LOW);
}

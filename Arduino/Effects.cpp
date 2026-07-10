#include "Effects.h"
#include "Config.h"

void Effects::ledOn()
{
    digitalWrite(CHEST_LED,HIGH);
}

void Effects::ledOff()
{
    digitalWrite(CHEST_LED,LOW);
}

void Effects::blink(int times)
{
    for(int i=0;i<times;i++)
    {
        ledOn();
        delay(150);

        ledOff();
        delay(150);
    }
}

void Effects::beep(int times)
{
    for(int i=0;i<times;i++)
    {
        tone(BUZZER,1000);
        delay(100);

        noTone(BUZZER);
        delay(100);
    }
}

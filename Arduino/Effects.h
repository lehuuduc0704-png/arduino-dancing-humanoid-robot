#ifndef EFFECTS_H
#define EFFECTS_H

#include <Arduino.h>

#include "Config.h"

class Effects
{
public:

    Effects();

    void begin();

    void ledOn();

    void ledOff();
};

#endif

#ifndef EFFECTS_H
#define EFFECTS_H

class Effects
{
public:
    void ledOn();
    void ledOff();
    void blink(int times);
    void beep(int times);

private:
    ServoController head;
    ServoController leftArm;
    ServoController rightArm;
    ServoController leftWing;
    ServoController rightWing;
    ServoController* servos[5];
    Effects effects;
};

#endif

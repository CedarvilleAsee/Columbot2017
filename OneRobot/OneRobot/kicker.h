#ifndef KICKER_H
#define KICKER_H

#include <Arduino.h>
#include <Servo.h>

class Kicker {
  private: 
    Servo kicker;
    
  public:
    Kicker(int kickerPin);
    void kick();
    void getReady();
};

#endif


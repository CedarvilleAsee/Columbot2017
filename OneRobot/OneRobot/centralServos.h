#ifndef CENTRALSERVOS_H
#define CENTRALSERVOS_H

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

class Mousetrap {
  private:
    Servo mousetrap;

  public:
    Mousetrap(int trapPin);
    void deploy();
    void deposit();
};

void dumperDump();

#endif


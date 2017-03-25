#include "constants.h"
#include "kicker.h"
#include <Arduino.h>
#include <Servo.h>

Kicker::Kicker(int kickerPin) {
    this->kicker.attach(kickerPin);
}

void Kicker::kick() {
  this->kicker.write(KICKER_KICKED);
}

void Kicker::getReady() {
  this->kicker.write(KICKER_READY);
}


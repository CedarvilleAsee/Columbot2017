#include "constants.h"
#include "centralServos.h"
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

Mousetrap::Mousetrap(int trapPin) {
  this->mousetrap.attach(trapPin);
}

void Mousetrap::deploy() {
  this->mousetrap.write(MOUSETRAP_DEPLOYED);
}

void Mousetrap::deposit() {
  this->mousetrap.write(MOUSETRAP_DEPOSITED);
}

void dumperDump() {
  Servo dumper;
  dumper.attach(DUMPER);
  dumper.write(DUMPER_DUMPED);
}


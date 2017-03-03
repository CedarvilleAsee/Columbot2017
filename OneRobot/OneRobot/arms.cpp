#include "constants.h"
#include "arms.h"
#include <Arduino.h>
#include <Servo.h>

arms::Arm::Arm(int innerPin, int outerPin, int clawPin) {
  this->inner.attach(innerPin);
  this->outer.attach(outerPin);
  this->claw.attach(clawPin);
}

void arms::Arm::setPosition(ArmPosition armPos){
  this->inner.write(armPos.inner);
  this->outer.write(armPos.outer);
  this->claw.write(armPos.claw);
}

arms::ArmPosition::ArmPosition(int inner, int outer, int claw) : inner(inner), outer(outer), claw(claw) {
}


#ifndef ARMS_H
#define ARMS_H

#include <Arduino.h>
#include <Servo.h>

class ArmPosition {
public:
  int inner;
  int outer;
  int claw;
  ArmPosition(int inner, int outer, int claw);
};

class Arm {
private:
  Servo inner;
  Servo outer;
  Servo claw;  
  
public:    
  Arm(int innerPin, int outerPin, int clawPin);

  void setPosition(ArmPosition armPos);
};

#endif

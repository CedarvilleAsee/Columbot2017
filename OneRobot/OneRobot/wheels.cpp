
#include "constants.h"
#include "wheels.h"
#include "pinNumbers.h"
#include <Arduino.h>
#include <Servo.h>

//Serial:  USB
//Serial1: bluetooth
#define prt Serial3
//#define DEBUG



void wheels::initialize() {
  // Setup wheel pins.
  // Setting up a wheel has six steps:
  //
  // Set the Power pin mode
  // Initializing the Power pin to 0
  //
  // Set the Forward pin mode
  // Set the Backward pin mode
  //
  // Initializing the Forward pin to HIGH
  // Initializing the Backward pin to LOW

  // Front left
  pinMode(WHEEL_PWM_FR, OUTPUT);
  analogWrite(WHEEL_PWM_FR, 0);

  pinMode(WHEEL_DIR_FL_F, OUTPUT);
  pinMode(WHEEL_DIR_FL_B, OUTPUT);

  digitalWrite(WHEEL_DIR_FL_F, HIGH);
  digitalWrite(WHEEL_DIR_FL_B, LOW);
  

  // Front right
  pinMode(WHEEL_PWM_FL, OUTPUT);
  analogWrite(WHEEL_PWM_FL, 0);

  pinMode(WHEEL_DIR_FR_F, OUTPUT);
  pinMode(WHEEL_DIR_FR_B, OUTPUT);

  digitalWrite(WHEEL_DIR_FR_F, HIGH);
  digitalWrite(WHEEL_DIR_FR_B, LOW);


  // Back left
  pinMode(WHEEL_PWM_BR, OUTPUT);
  analogWrite(WHEEL_PWM_BR, 0);

  pinMode(WHEEL_DIR_BL_F, OUTPUT);
  pinMode(WHEEL_DIR_BL_B, OUTPUT);

  digitalWrite(WHEEL_DIR_BL_F, HIGH);
  digitalWrite(WHEEL_DIR_BL_B, LOW);


  // Back right
  pinMode(WHEEL_PWM_BL, OUTPUT);
  analogWrite(WHEEL_PWM_BL, 0);

  pinMode(WHEEL_DIR_BR_F, OUTPUT);
  pinMode(WHEEL_DIR_BR_B, OUTPUT);

  digitalWrite(WHEEL_DIR_BR_F, HIGH);
  digitalWrite(WHEEL_DIR_BR_B, LOW);



  // The last step is to make sure all the standby pins are set 
  // to the correct mode and powered high
  pinMode(WHEEL_PWM_FIRST_STBY, OUTPUT);
  digitalWrite(WHEEL_PWM_FIRST_STBY, HIGH);
  
  pinMode(WHEEL_PWM_SECOND_STBY, OUTPUT);
  digitalWrite(WHEEL_PWM_SECOND_STBY, HIGH);
}


void wheels::powerWheel(Wheel wheel, WheelDirection direction,  int speed) {
  // The direction of the wheels is determined by two pins, WHEEL_DIR_xx_F and WHEEL_DIR_xx_B.
  // F and B stand for Forward and Backward, but that is an oversimplification that is useful
  // for remembering which pin is which. The wheels can do four things: Coast, Go forward, Go backward, and Brake. 
  // The following is a truth table for the pins:
  // F B | Direction
  // 0 0 | Coast
  // 0 1 | Backwards
  // 1 0 | Forward
  // 1 1 | Brake
  switch(wheel) {
    case FrontRight:
      if (direction == Forward){
        digitalWrite(WHEEL_DIR_FR_F, HIGH);
        digitalWrite(WHEEL_DIR_FR_B, LOW);
      }
      else if (direction == Backward){
        digitalWrite(WHEEL_DIR_FR_F, LOW);
        digitalWrite(WHEEL_DIR_FR_B, HIGH);
      }
      else if (direction == Coast){
        digitalWrite(WHEEL_DIR_FR_F, LOW);
        digitalWrite(WHEEL_DIR_FR_B, LOW);
      }
      else if (direction == Brake){
        digitalWrite(WHEEL_DIR_FR_F, HIGH);
        digitalWrite(WHEEL_DIR_FR_B, HIGH);
      }
      analogWrite(WHEEL_PWM_FR, speed);
    break;
    case FrontLeft:
      if (direction == Forward){
        digitalWrite(WHEEL_DIR_FL_F, HIGH);
        digitalWrite(WHEEL_DIR_FL_B, LOW);
      }
      else if (direction == Backward){
        digitalWrite(WHEEL_DIR_FL_F, LOW);
        digitalWrite(WHEEL_DIR_FL_B, HIGH);
      }
      else if (direction == Coast){
        digitalWrite(WHEEL_DIR_FL_F, LOW);
        digitalWrite(WHEEL_DIR_FL_B, LOW);
      }
      else if (direction == Brake){
        digitalWrite(WHEEL_DIR_FL_F, HIGH);
        digitalWrite(WHEEL_DIR_FL_B, HIGH);
      }
      analogWrite(WHEEL_PWM_FL, speed);
    break;
    case BackRight:
      if (direction == Forward){
        digitalWrite(WHEEL_DIR_BR_F, HIGH);
        digitalWrite(WHEEL_DIR_BR_B, LOW);
      }
      else if (direction == Backward){
        digitalWrite(WHEEL_DIR_BR_F, LOW);
        digitalWrite(WHEEL_DIR_BR_B, HIGH);
      }
      else if (direction == Coast){
        digitalWrite(WHEEL_DIR_BR_F, LOW);
        digitalWrite(WHEEL_DIR_BR_B, LOW);
      }
      else if (direction == Brake){
        digitalWrite(WHEEL_DIR_BR_F, HIGH);
        digitalWrite(WHEEL_DIR_BR_B, HIGH);
      }
      analogWrite(WHEEL_PWM_BR, speed);
    break;
    case BackLeft:
      if (direction == Forward){
        digitalWrite(WHEEL_DIR_BL_F, HIGH);
        digitalWrite(WHEEL_DIR_BL_B, LOW);
      }
      else if (direction == Backward){
        digitalWrite(WHEEL_DIR_BL_F, LOW);
        digitalWrite(WHEEL_DIR_BL_B, HIGH);
      }
      else if (direction == Coast){
        digitalWrite(WHEEL_DIR_BL_F, LOW);
        digitalWrite(WHEEL_DIR_BL_B, LOW);
      }
      else if (direction == Brake){
        digitalWrite(WHEEL_DIR_BL_F, HIGH);
        digitalWrite(WHEEL_DIR_BL_B, HIGH);
      }
      analogWrite(WHEEL_PWM_BL, speed);
    break;
  }
}

void wheels::powerAllWheels(WheelDirection direction, int speed) {
  powerWheel(FrontRight, direction, speed);
  powerWheel(FrontLeft, direction, speed);
  powerWheel(BackRight, direction, speed);
  powerWheel(BackLeft, direction, speed);
}

void wheels::goForward(int speed) {
  powerAllWheels(Forward, speed);
}

void wheels::brake() {
  powerAllWheels(Brake, 0);
}

void wheels::goBackward(int speed) {
  powerAllWheels(Backward, speed);
}

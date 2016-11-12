#include "constants.h"
//#include "nose.h"
#include "wheels.h"
//#include "rings.h"
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
    case Wheel::FrontRight:
      if (direction == WheelDirection::Forward){
        digitalWrite(WHEEL_DIR_FR_F, HIGH);
        digitalWrite(WHEEL_DIR_FR_B, LOW);
      }
      else if (direction == WheelDirection::Backward){
        digitalWrite(WHEEL_DIR_FR_F, LOW);
        digitalWrite(WHEEL_DIR_FR_B, HIGH);
      }
      else if (direction == WheelDirection::Coast){
        digitalWrite(WHEEL_DIR_FR_F, LOW);
        digitalWrite(WHEEL_DIR_FR_B, LOW);
      }
      else if (direction == WheelDirection::Brake){
        digitalWrite(WHEEL_DIR_FR_F, HIGH);
        digitalWrite(WHEEL_DIR_FR_B, HIGH);
      }
      analogWrite(WHEEL_PWM_FR, 0);
    break;
    case Wheel::FrontLeft:
      if (direction == WheelDirection::Forward){
        digitalWrite(WHEEL_DIR_FL_F, HIGH);
        digitalWrite(WHEEL_DIR_FL_B, LOW);
      }
      else if (direction == WheelDirection::Backward){
        digitalWrite(WHEEL_DIR_FL_F, LOW);
        digitalWrite(WHEEL_DIR_FL_B, HIGH);
      }
      else if (direction == WheelDirection::Coast){
        digitalWrite(WHEEL_DIR_FL_F, LOW);
        digitalWrite(WHEEL_DIR_FL_B, LOW);
      }
      else if (direction == WheelDirection::Brake){
        digitalWrite(WHEEL_DIR_FL_F, HIGH);
        digitalWrite(WHEEL_DIR_FL_B, HIGH);
      }
      analogWrite(WHEEL_PWM_FL, 0);
    break;
    case Wheel::BackRight:
      if (direction == WheelDirection::Forward){
        digitalWrite(WHEEL_DIR_BR_F, HIGH);
        digitalWrite(WHEEL_DIR_BR_B, LOW);
      }
      else if (direction == WheelDirection::Backward){
        digitalWrite(WHEEL_DIR_BR_F, LOW);
        digitalWrite(WHEEL_DIR_BR_B, HIGH);
      }
      else if (direction == WheelDirection::Coast){
        digitalWrite(WHEEL_DIR_BR_F, LOW);
        digitalWrite(WHEEL_DIR_BR_B, LOW);
      }
      else if (direction == WheelDirection::Brake){
        digitalWrite(WHEEL_DIR_BR_F, HIGH);
        digitalWrite(WHEEL_DIR_BR_B, HIGH);
      }
      analogWrite(WHEEL_PWM_BR, 0);
    break;
    case Wheel::BackLeft:
      if (direction == WheelDirection::Forward){
        digitalWrite(WHEEL_DIR_BL_F, HIGH);
        digitalWrite(WHEEL_DIR_BL_B, LOW);
      }
      else if (direction == WheelDirection::Backward){
        digitalWrite(WHEEL_DIR_BL_F, LOW);
        digitalWrite(WHEEL_DIR_BL_B, HIGH);
      }
      else if (direction == WheelDirection::Coast){
        digitalWrite(WHEEL_DIR_BL_F, LOW);
        digitalWrite(WHEEL_DIR_BL_B, LOW);
      }
      else if (direction == WheelDirection::Brake){
        digitalWrite(WHEEL_DIR_BL_F, HIGH);
        digitalWrite(WHEEL_DIR_BL_B, HIGH);
      }
      analogWrite(WHEEL_PWM_BL, 0);
    break;
  }
}

void wheels::powerAllWheels(WheelDirection direction, int speed) {
  powerWheel(Wheel::FrontRight, direction, speed);
  powerWheel(Wheel::FrontLeft, direction, speed);
  powerWheel(Wheel::BackRight, direction, speed);
  powerWheel(Wheel::BackLeft, direction, speed);
}

void wheels::stopAllWheels() {
  powerAllWheels(WheelDirection::Brake, 0);
}

// drives wheels with differential based on angle
/*void wheels::drive(int angle, int speed) {
    int left;
    int right;
    
    if (angle > 0) {
        right  = speed;
        left   = speed * ratio(angle); //max angle here is +45 left goes 1/4 as fast
    } else {
        left   = speed;
        right  = speed * ratio(angle); //"max" angle here is -45 _CHANGE
    }

    driveWheels(left, right);
    
    return;
}*/

/*
// drives wheels forwards and backwards; > 0 is forwards
void wheels::driveWheels(int left, int right) {

    if (left > 0) {
        // drive left motor forward
        digitalWrite(WHEEL_DIR_BL_F, HIGH);
        digitalWrite(WHEEL_DIR_BL_B, LOW);

    } else if (left < 0) {
        // drive left motor backwards
        digitalWrite(WHEEL_DIR_BL_F, LOW);
        digitalWrite(WHEEL_DIR_BL_B, HIGH);
        left = -left;

    } else {
        // stop left motor
        digitalWrite(WHEEL_DIR_BL_F, LOW);
        digitalWrite(WHEEL_DIR_BL_B, LOW);
    }


    if (right > 0) {
        // drive right motor forward
        digitalWrite(WHEEL_DIR_BR_F, HIGH);
        digitalWrite(WHEEL_DIR_BR_B, LOW);

    } else if (right < 0) {
        // drive right motor backwards
        digitalWrite(WHEEL_DIR_BR_F, LOW);
        digitalWrite(WHEEL_DIR_BR_B, HIGH);
        right = -right;

    } else {
        // stop right motor
        digitalWrite(WHEEL_DIR_BR_F, LOW);
        digitalWrite(WHEEL_DIR_BR_B, LOW);
    }

    // cap pwm at 255
    if (left > 255)  { left  = 255; }
    if (right > 255) { right = 255; }
    
    //send pwm to motors
    analogWrite(PWMR, right);
    analogWrite(PWML, left);
}

double wheels::ratio(int angle) {
    
  if(angle > 0){return angle / -60.0 + 1.0;}
  else {return angle / 60.0 + 1.0;}
  //if +-45 degrees, then .25 ----- if 0 degrees then 1 _CHANGE
}

void wheels::STOPIT() {
    driveWheels(0, 0);
    //while(true) { rings::stopRing(); }
}*/


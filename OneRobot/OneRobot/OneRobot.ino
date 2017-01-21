#include <Servo.h>
//#include <lineFollow.h>
#include "pinNumbers.h"
#include "constants.h"
#include "wheels.h"
#include "arms.h"

using namespace wheels;

Servo firstServe;
Servo secondServe;
Servo thridServe;
Servo fourthServe;
Servo fifthServe;
Servo sixthServe;
Servo seventhServe;
Servo eightServe;
Servo ninthServe;
Servo serve;
arms::Arm rightArm;
arms::Arm leftArm;

void setup(){
 
  // put your setup code here, to run once:
  for (int i = 0; i < NUM_OF_SENSORS; ++i) {
        pinMode(LINE_SENSOR_PINS[i], INPUT);
  }


  //LEDs on shield
  pinMode(LEDG, OUTPUT);
  pinMode(LEDY, OUTPUT);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDY, HIGH);

  wheels::initialize();
  arms::initialize(leftArm, rightArm);
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT);
  
  //start serial communication
  //prt.begin(115200);


  //serve.attach(RIGHT_CLAW);  

//  leftArm.inner.attach(LEFT_INNER_ARM);
//  leftArm.outer.attach(LEFT_OUTER_ARM);
//  leftArm.claw.attach(LEFT_CLAW);
//  rightArm.inner.attach(RIGHT_INNER_ARM);
//  rightArm.outer.attach(RIGHT_OUTER_ARM);
//  rightArm.claw.attach(RIGHT_CLAW);



}

int lastButton1 = 0;
bool isArmOpen = true;

int lastButton2 = 0;
bool isClawOpen = true;

void loop() {
  
  // declaring armstates for the main to use
  arms::ArmState readyToCatch;//arm is open and claw is open
  readyToCatch.claw = 95;
  readyToCatch.inner = 50;
  readyToCatch.outer = 50;
  arms::ArmState barrelCatch;//arm is open and claw is closed
  barrelCatch.claw = 73;
  barrelCatch.inner = 50;
  barrelCatch.outer = 50;
  arms::ArmState predrop;//arm is closed and claw is closed
  predrop.claw = 73;
  predrop.inner = 150;
  predrop.outer = 150;
  arms::ArmState barrelDrop;//arm is closed and claw is open
  barrelDrop.claw = 95;
  barrelDrop.inner = 150;
  barrelDrop.outer = 150;  



//State Machine Begginings
  //update Sensors
  //update Arms
  //update wheels




//  // Toggle between all the armstates
//  
//  int button1 = digitalRead(BUTTON1);
//  int button2 = digitalRead(BUTTON2);
//
//  if (button1 != lastButton1) {
//    lastButton1 = button1;
//    if (button1 == LOW) {
//      if (isArmOpen) {
//        isArmOpen = false;
//        setArmState(rightArm, armOpen);
//      }
//      else {
//        isArmOpen = true;
//        setArmState(rightArm, armClosed);
//      }
//    }
//  }
//  if (button2 != lastButton2) {
//    lastButton2 = button2;
//    if (button2 == LOW) {
//      if (isClawOpen) {
//        isClawOpen = false;
//        setArmState(rightArm, clawClose);
//      }
//      else {
//        isClawOpen = true;
//        setArmState(rightArm, clawOpen);        
//      }
//    }
//  }
}

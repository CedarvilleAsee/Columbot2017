//Updated 1-28-17
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
  Serial.begin(115200);
  Serial.write("Hello from Robot1!");
  
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
int lastButton2 = 0;
int command=0;
int command1=0;
int command2=0;
int command3=0;
int armStatus=0;

void loop() {
  
  // declaring armstates for the main to use
  arms::ArmState straightArm;//arm is open and claw is closed
  straightArm.claw = CLAW_CLOSED;
  straightArm.inner = 90;
  straightArm.outer = 10;
  arms::ArmState closed;//arm is closed and claw is open
  closed.claw = CLAW_OPEN;
  closed.inner = 180;
  closed.outer = 120;
  arms::ArmState preped;//arm is closed and claw is closed
  preped.claw = CLAW_CLOSED;
  preped.inner = 180;
  preped.outer = 120;
  arms::ArmState barrelDrop;//arm is closed and claw is open
  barrelDrop.claw = CLAW_OPEN;
  barrelDrop.inner = 90;
  barrelDrop.outer = 10;  



  if (Serial.available() > 0 ){
    command = Serial.read();
    command1 = Serial.read();
    command2 = Serial.read();
    command3 = Serial.read();
    Serial.print("I recieved: ");
    Serial.println(command);
  }
  switch (command) {
    case ARM:
      if (command1 == CLOSED) {
        if (command2 == CLAW){
          if (command3 == OPEN){
            setArmState(rightArm, closed);
            armStatus = ARMSTATE_CLOSED;
          }
          else if (command3 == OPEN){
            setArmState(rightArm, preped);
            armStatus = ARMSTATE_PREPED;
          }
        }
      }
      else if (command1 == OPEN){
        if (command2 == CLAW){
          if (command3 == OPEN){
            setArmState(rightArm, straightArm);
            armStatus= ARMSTATE_STRAIGHTARM;
          }
          else if (command3 == OPEN){
            setArmState(rightArm, barrelDrop);
            armStatus = ARMSTATE_BARRELDROP;
          }
        }
      }
      break;
    case CLAW:
      if (command1 == OPEN && armStatus == ARMSTATE_STRAIGHTARM){
        setArmState(rightArm, barrelDrop);
        armStatus = ARMSTATE_BARRELDROP;
      }
      else if (command1 == OPEN && armStatus == ARMSTATE_PREPED){
        setArmState(rightArm, closed);
        armStatus = ARMSTATE_CLOSED;
      }
      else if (command1 == CLOSED && armStatus == ARMSTATE_CLOSED){
        setArmState(rightArm, preped);
        armStatus = ARMSTATE_PREPED;
      }
      else if (command1 == CLOSED && armStatus == ARMSTATE_PREPED){
        setArmState(rightArm, closed);
        armStatus = ARMSTATE_CLOSED;
      } 

  }

//State Machine Begginings
  //update Sensors
  //update Arms
  //update wheels

//  setArmState(rightArm,closed);


  // Toggle between all the armstates
  
//  int button1 = digitalRead(BUTTON1);
//  if (button1 > 0){
//    lastButton1 = button1;
//    lastButton2 = 0;
//  }
//  int button2 = digitalRead(BUTTON2);
//  if (button2>0){
//    lastButton2 = button2;
//    lastButton1 = 0;
//  }
//
//  if (lastButton1 > 0 && armStatus < 20 ) {
//    setArmState(rightArm, straightArm);
//    armStatus = ARMSTATE_STRAIGHTARM;
//  }
//  else if (lastButton1>0 && armStatus == ARMSTATE_STRAIGHTARM){
//    setArmState(rightArm, barrelDrop);
//    armStatus = ARMSTATE_BARRELDROP;
//  }
//  else if (lastButton2>0 && armStatus >=20){
//    setArmState(rightArm, closed);
//    armStatus = ARMSTATE_CLOSED;//represents a closed state with open claw
//  }
//  else if (lastButton2>0 && armStatus == ARMSTATE_CLOSED){
//    setArmState(rightArm, preped);
//    armStatus = ARMSTATE_PREPED;
//  }




//  if (button1 != lastButton1) {
//    lastButton1 = button1;
//    if (button1 == LOW) {
//      if (isArmOpen) {
//        isArmOpen = false;
//        setArmState(rightArm, readyToCatch);
//      }
//      else {
//        isArmOpen = true;
//        setArmState(rightArm, preDrop);
//      }
//    }
//  }
//  if (button2 != lastButton2) {
//    lastButton2 = button2;
//    if (button2 == LOW) {
//      if (isClawOpen) {
//        isClawOpen = false;
//        setArmState(rightArm, barrelCatch);
//      }
//      else {
//        isClawOpen = true;
//        setArmState(rightArm, barrelDrop);        
//      }
//    }
//  }
}

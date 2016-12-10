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
  
  //start serial communication
  //prt.begin(115200);

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT);
  //serve.attach(RIGHT_CLAW);  
  arms::initialize(leftArm, rightArm);
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

  // A bunch of armstates
  arms::ArmState armOpen;
  armOpen.claw = 95;
  armOpen.inner = 50;
  armOpen.outer = 50;
  arms::ArmState clawClose;
  clawClose.claw = 73;
  clawClose.inner = 50;
  clawClose.outer = 50;
  arms::ArmState clawOpen;
  clawOpen.claw = 95;
  clawOpen.inner = 50;
  clawOpen.outer = 50;  
  arms::ArmState armClosed;
  armClosed.claw = 73;
  armClosed.inner = 150;
  armClosed.outer = 150;

  // Toggle between all the armstates
  
  int button1 = digitalRead(BUTTON1);
  int button2 = digitalRead(BUTTON2);

  if (button1 != lastButton1) {
    lastButton1 = button1;
    if (button1 == LOW) {
      if (isArmOpen) {
        isArmOpen = false;
        setArmState(rightArm, armOpen);
      }
      else {
        isArmOpen = true;
        setArmState(rightArm, armClosed);
      }
    }
  }
  if (button2 != lastButton2) {
    lastButton2 = button2;
    if (button2 == LOW) {
      if (isClawOpen) {
        isClawOpen = false;
        setArmState(rightArm, clawClose);
      }
      else {
        isClawOpen = true;
        setArmState(rightArm, clawOpen);        
      }
    }
  }
}

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

  pinMode(BUTTON1, INPUT);
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

void loop() {
  /*while(digitalRead(BUTTON1));
  wheels::powerAllWheels(Forward, 100);
  for(int i=1; i<=10; i++){
    digitalWrite(LEDG, LOW);
    delay(500);
    digitalWrite(LEDG, HIGH);
    delay(500);
  }
  wheels::stopAllWheels();
  */
  arms::ArmState armOpen;
  armOpen.claw = 110;
  armOpen.inner = 70;
  armOpen.outer = 70;
  arms::ArmState armClosed;
  armClosed.claw = 78;
  armClosed.inner = 140;
  armClosed.outer = 140;
  digitalWrite(LEDG,LOW);
  while(digitalRead(BUTTON2));
  digitalWrite(LEDG,HIGH);
  //rightArm.claw.write(110);
  arms::setArmState(rightArm, armOpen);
  while(digitalRead(BUTTON1)); 
  digitalWrite(LEDG,LOW); 
//  rightArm.claw.write(78);
  arms::setArmState(rightArm, armClosed);

}

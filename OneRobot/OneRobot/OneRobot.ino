//Updated 1-28-17
#include <Servo.h>
//#include <lineFollow.h>
#include "pinNumbers.h"
#include "constants.h"
#include "wheels.h"
#include "arms.h"

using namespace wheels;

int state = 0;
long startTime = 0;
long timeOpened;
arms::Arm rightArm;
arms::Arm leftArm;
arms::ArmState closed;
arms::ArmState midState;
arms::ArmState preppedToDrop;
arms::ArmState drop;


void setup(){
 
  // put your setup code here, to run once:
//  for (int i = 0; i < NUM_OF_SENSORS; ++i) {
//        pinMode(LINE_SENSOR_PINS[i], INPUT);
//  }


  //LEDs on shield
  pinMode(LEDG, OUTPUT);
  pinMode(LEDY, OUTPUT);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDY, HIGH);

  wheels::initialize();
  arms::initialize(leftArm, rightArm);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  
  Serial.begin(115200);

  closed.claw = CLAW_CLOSED;
  closed.inner = INNER_CLOSED;
  closed.outer = OUTER_CLOSED;

  midState.claw = CLAW_CLOSED;
  midState.inner = INNER_OPEN;
  midState.outer = OUTER_CLOSED;

  preppedToDrop.claw = CLAW_CLOSED;
  preppedToDrop.inner = INNER_OPEN;
  preppedToDrop.outer = OUTER_OPEN;

  drop.claw = CLAW_OPEN;
  drop.inner = INNER_OPEN;
  drop.outer = OUTER_OPEN;

  startTime = millis();
}



void loop() {
  Serial.println(analogRead(ANALOG_INPUT));
  switch (state) {
    case 0: // Initial driving state.
        setArmState(rightArm, closed);
        if (digitalRead(BUTTON1) == LOW) {
          startTime = millis();
          state++;
        }
      break;
    case 1: // Open elbows; advance to next state after delay.
      wheels::powerAllWheels(wheels::Forward, 100);
      setArmState(rightArm, midState);
      if(millis()-startTime > 500){
        state++;
        timeOpened = millis();
      }
      break;
    case 2: // Open forearms.
      wheels::powerAllWheels(wheels::Forward, 100);
      setArmState(rightArm, preppedToDrop);
      if (millis() - timeOpened > 5000) {
        state++;
      }
      break;
    case 3: // Drop barrels after 
      wheels::powerAllWheels(wheels::Forward, 100);
      setArmState(rightArm, drop);
      break;
    case 4:
      break;
  }
}


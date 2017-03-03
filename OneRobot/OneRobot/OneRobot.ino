//Updated 1-28-17
#include <Servo.h>
//#include <lineFollow.h>
#include "pinNumbers.h"
#include "constants.h"
#include "wheels.h"
#include "arms.h"

using namespace wheels;

int state = 0;
long runStartTime = 0;
long stateStartTime = 0;
long timeOpened;
arms::Arm rightArm;
arms::Arm leftArm;
arms::ArmState armsFoldedIn;
arms::ArmState elbowsOpen;
arms::ArmState armsPreppedToDrop;
arms::ArmState clawsOpened;

void goToState(int targetState) {
  state = targetState;
  stateStartTime = millis();
}

void setup(){


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

  armsFoldedIn.claw = CLAW_CLOSED;
  armsFoldedIn.inner = INNER_CLOSED;
  armsFoldedIn.outer = OUTER_CLOSED;

  elbowsOpen.claw = CLAW_CLOSED;
  elbowsOpen.inner = INNER_OPEN;
  elbowsOpen.outer = OUTER_CLOSED;

  armsPreppedToDrop.claw = CLAW_CLOSED;
  armsPreppedToDrop.inner = INNER_OPEN;
  armsPreppedToDrop.outer = OUTER_OPEN;

  clawsOpened.claw = CLAW_OPEN;
  clawsOpened.inner = INNER_OPEN;
  clawsOpened.outer = OUTER_OPEN;

  runStartTime = millis();
}



void loop() {
  Serial.println(analogRead(ANALOG_INPUT));
  switch (state) {

    // The initial state of the robot at the start of the run.
    // Makes sure the arms are folded in and the wheels are not driving.
    // Exits when a button is pressed.
    case 0:
      setArmState(rightArm, armsFoldedIn);
      if (digitalRead(BUTTON1) == LOW) {
        runStartTime = millis();
        goToState(1);
      }
      break;

    // The robot goes from the starting position to partway along the open fairway.
    // Powers the wheels forward.
    // Exits after a short time (half a second).
    case 1:
      wheels::powerAllWheels(wheels::Forward, 100);
      if (millis() - stateStartTime > 500) {
        goToState(2);
      }

    // We are out in the open, and we need to open the arms, but we can't just swing the arms wide open.
    // Powers wheels forward. Opens elbows.
    // Exits after short time (half a second).
    case 2:
      wheels::powerAllWheels(wheels::Forward, 100);
      setArmState(rightArm, elbowsOpen);
      if(millis()-stateStartTime > 500){
        goToState(3);
      }
      break;

    // We are getting closer to the first islands. We need to prepare to drop the barrels.
    // Power wheels forward. Open forearms and claws.
    // Exits after detecting an island.
    // TODO: At the moment, this state exits after a time delay because we do not have island sensors yet.
    case 3:
      wheels::powerAllWheels(wheels::Forward, 100);
      setArmState(rightArm, elbowsOpen);
      if (millis() - stateStartTime > 5000) {
        goToState(4);
      }
      break;

    // We are at the islands and need to drop the barrels. We also need to make it possible to pick up the next barrels.
    // Power wheels forward. Open claw to drop barrels.
    // Exits immediately because barrels can be dropped immediately.
    // TODO: Evaluate whether this needs to be a separate state. Since it exits immediately, it could be done in the previous state.
    case 4:
      wheels::powerAllWheels(wheels::Forward, 100);
      setArmState(rightArm, clawsOpened);
      break;
  }
}


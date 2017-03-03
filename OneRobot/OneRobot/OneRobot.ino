//Updated 1-28-17
#include <Servo.h>
//#include <lineFollow.h>
#include "pinNumbers.h"
#include "constants.h"
#include "wheels.h"
#include "arms.h"

using namespace wheels;

// The current state that we are in.
int state = 0;

// The time that the whole run of the course started.
long runStartTime = 0;

// The time that the current state was entered.
long stateStartTime = 0;

// Possible arm positions.
arms::Arm leftArm(LEFT_INNER_ARM, LEFT_OUTER_ARM, LEFT_CLAW);
arms::Arm rightArm(RIGHT_INNER_ARM, RIGHT_OUTER_ARM, RIGHT_CLAW);
arms::ArmPosition armsFoldedIn(CLAW_CLOSED, INNER_CLOSED, OUTER_CLOSED);
arms::ArmPosition elbowsOpen(CLAW_CLOSED, INNER_OPEN, OUTER_CLOSED);
arms::ArmPosition armsPreppedToDrop(CLAW_CLOSED, INNER_OPEN, OUTER_OPEN);
arms::ArmPosition clawsOpened(CLAW_OPEN, INNER_OPEN, OUTER_OPEN);


// TODO: Evaluate need for this function.
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
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  
  Serial.begin(115200);

  runStartTime = millis();
}

void loop() {
  Serial.println(analogRead(ANALOG_INPUT));
  switch (state) {
    // The initial state of the robot at the start of the run.
    // Makes sure the arms are folded in and the wheels are not driving.
    // Exits when a button is pressed.
    case 0:
      rightArm.setPosition(armsFoldedIn);
      if (digitalRead(BUTTON1) == LOW) {
        runStartTime = millis();
        goToState(1);
      }
      break;

    // The robot goes from the starting position to partway along the open fairway.
    // Powers the wheels forward.
    // Exits after a short time (half a second).
    case 1:
      wheels::goForward(FULL_SPEED);
      if (millis() - stateStartTime > 500) {
        goToState(2);
      }

    // We are out in the open, and we need to open the arms, but we can't just swing the arms wide open.
    // Powers wheels forward. Opens elbows.
    // Exits after short time (half a second).
    case 2:
      wheels::goForward(FULL_SPEED);
      rightArm.setPosition(elbowsOpen);
      if(millis()-stateStartTime > 500){
        goToState(3);
      }
      break;

    // We are getting closer to the first islands. We need to prepare to drop the barrels.
    // Power wheels forward. Open forearms and claws.
    // Exits after detecting an island.
    // TODO: At the moment, this state exits after a time delay because we do not have island sensors yet.
    case 3:
      wheels::goForward(FULL_SPEED);
      rightArm.setPosition(elbowsOpen);
      if (millis() - stateStartTime > 5000) {
        goToState(4);
      }
      break;

    // We are at the islands and need to drop the barrels. We also need to make it possible to pick up the next barrels.
    // Power wheels forward. Open claw to drop barrels.
    // Exits immediately because barrels can be dropped immediately.
    // TODO: Evaluate whether this needs to be a separate state. Since it exits immediately, it could be done in the previous state.
    case 4:
      wheels::goForward(FULL_SPEED);
      rightArm.setPosition(clawsOpened);
      goToState(5);
      break;

    // The following states are tentative and have not been tested.

    // We need to pick up the barrels. We may be moving to quickly, so we will slow down.
    // Power wheels forward at slower speed. Move arms to barrel pickup position.
    // Exits when the claw sensors detect a barrel coming close enough to the claw.
    // TODO: Get sensors to work. Make a good armPosition for this state.
    case 5:
      wheels::goForward(HALF_SPEED);
      rightArm.setPosition(/*armsReadyToPickup*/clawsOpened);
      if (millis() - stateStartTime > 1000) {
        goToState(6);
      }
      break;
  }
}


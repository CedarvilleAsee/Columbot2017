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
Arm leftArm(LEFT_INNER_ARM, LEFT_OUTER_ARM, LEFT_CLAW);
Arm rightArm(RIGHT_INNER_ARM, RIGHT_OUTER_ARM, RIGHT_CLAW);
ArmPosition armsFoldedIn(CLAW_CLOSED, INNER_CLOSED, OUTER_CLOSED);
ArmPosition elbowsOpen(CLAW_CLOSED, INNER_OPEN, OUTER_CLOSED);
ArmPosition armsPreppedToDrop(CLAW_CLOSED, INNER_OPEN, OUTER_OPEN);
ArmPosition clawsOpened(CLAW_OPEN, INNER_OPEN, OUTER_OPEN);


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
    // Power wheels forward. Open forearms.
    // Exits after detecting an island.
    // TODO: At the moment, this state exits after a time delay because we do not have island sensors yet.
    case 3:
      wheels::goForward(FULL_SPEED);
      rightArm.setPosition(armsPreppedToDrop);
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
    // Exits when a claw sensor detects a barrel coming close enough to the claw.
    // NOTE: States fork based on which claw grabs first.
    // TODO: Get sensors to work. Make a good armPosition for this state.
    case 5:
      wheels::goForward(HALF_SPEED);
      rightArm.setPosition(/*armsReadyToPickup*/clawsOpened);
      if (millis() - stateStartTime > 1000) {//right
        goToState(6);
      }
      if (millis() - stateStartTime > 1000) {//left
        goToState(7);
      }
      break;

    // The foillowing states are forked and similar
    // Powering wheels forward at slower speed. One state picks up left. One state picks up right.
    // Exits when the oposite barrel is picked up.

    // We have picked up the right barrel and are waiting for the right barrel.
    // Powering wheels medium speed; wait for left barrel.
    // Exits when left barrel sensed
    case 6:
      wheels::goForward(HALF_SPEED);
      rightArm.setPosition(/*close right*/clawsOpened);
      if (millis() - stateStartTime > 1000) {//picks up left
        rightArm.setPosition(armsPreppedToDrop);
        goToState(8);
      }
      break;

    // We have picked up the left barrel and are waiting for the right barrel.
    // Powering wheels medium speed; wait for right barrel.
    // Exits when right barrel sensed.
    case 7:
      wheels::goForward(HALF_SPEED);
      rightArm.setPosition(/*close left*/clawsOpened);
      if (millis() - stateStartTime > 1000) {//picks up right
        rightArm.setPosition(armsPreppedToDrop);
        goToState(8);
      }
      break;

    // We picked up both barrels and we are bringing them into chasis
    // Powering wheels medium speed, bringing arms in at elbows, preped to kick barrel waiting for center island
    // Exits when island is sensed
    case 8:
      wheels::goForward(HALF_SPEED);
      rightArm.setPosition(elbowsOpen);
      kicker.getReady();
      if (millis() - stateStartTime > 1000) {//detects center island
        goToState(9);
      }
      break;

    // We have detected center island
    // Powering all wheels medium speed, bring arms in final state, kicking barrel,
    // Exits after small time
    case 9:
      wheels::goForward(HALF_SPEED);
      rightArm.setPosition(armsFoldedIn);
      kicker.kick();
      if (millis() - stateStartTime > 1000) {//detect exit island
        goToState(10);
      }
      break;

    case 10:
      wheels::goForward(HALF_SPEED);
      rightArm.setPosition(armsChasisDeposit);
      if (millis() - stateStartTime > 1000) {//small delay
        goToState(11);
      }
      break;
      
    // We are waiting for second center island 
    // Powering all wheels full speed, drop mouse trap 2, prep to kick again, deposit barrels
    // Exits when island is sensed
    case 11:
      wheels::goForward(FULL_SPEED);
      rightArm.setPosition(armsPickupFromArm);
      kicker.getReady();
      mousetrap2.deploy();
      if (millis() - stateStartTime > 1000) {//detect island
        goToState(12);
      }
      break;

    case 12:
      wheels::goForward(FULL_SPEED);
      kicker.kick();
      rightArm.setPosition(elbowsOpen);
      if (millis() - stateStartTime > 1000) {//dectect end of island
        goToState(13);
      }
      break;

    

    case 13:
      wheels::goForward(HALF_SPEED);
      rightArm.setPosition(armsPreppedToDrop);
      if (millis() - stateStartTime > 500) {//small delay
        goToState(14);
      }
      break;

    case 14:
      wheels::goForward(HALF_SPEED);
      rightArm.setPosition(clawsOpened);
      if (millis() - stateStartTime > 500) {//small delay
        goToState(15);
      }
      break;

    case 15:
      wheels::goForward(HALF_SPEED);
      rightArm.setPosition(lastPickupSetup);
      if (millis() - stateStartTime > 500) {//sense back wall
        goToState(16);
      }
      break;

    case 16:
      wheels::brake();
      rightArm.setPosition(lastPickup);
      if (millis() - stateStartTime > 500) {
        goToState(17);
      }
      break;

    case 17:
      wheels::goBackward(FULL_SPEED);
      rightArm.setPosition(elbowsOpen);
      if (millis() - stateStartTime > 500) {
        goToState(18);
      }
      break;
      
    case 18:
      wheels::goBackward(FULL_SPEED);
      rightArm.setPosition(armsFoldedIn);
      if (millis() - stateStartTime > 500) {
        goToState(19);
      }
      break;

            
    case 19:
      wheels::goBackward(FULL_SPEED);
      rightArm.setPosition(armsChasisDeposit);
      if (millis() - stateStartTime > 500) {
        goToState(20);
      }
      break;

      
    case 20:
      wheels::goBackward(FULL_SPEED);
      rightArm.setPosition(armsFoldedIn);
      if (millis() - stateStartTime > 500) {
        goToState(21);
      }
      break;

    case 21:
      wheels::goBackward(FULL_SPEED);
      // deposit mousetraps
      if (millis() - stateStartTime > 500) {
        goToState(22);
      }
      break;

    case 22:
      wheels::goBackward(FULL_SPEED);
      // reset all stuff.
      if (millis() - stateStartTime > 500) {// Waiting for back wall
        goToState(22);
      }
      break;

    case 23:
      wheels::goBackward(FULL_SPEED);
      // Deploy barrels to home.
      if (millis() - stateStartTime > 2000) {
        // Serve root beer floats
      }
      break;

    // TODO: Hammer out micro arm states.
  }
}


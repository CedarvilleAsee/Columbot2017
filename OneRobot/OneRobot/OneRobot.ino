//Updated 1-28-17
#include <Servo.h>
#include "pinNumbers.h"
#include "constants.h"
#include "wheels.h"
#include "arms.h"
#include "centralServos.h"

using namespace wheels;

// The current state that we are in.
int state = 0;

// The time that the whole run of the course started.
long runStartTime = 0;

// The time that the current state was entered.
long stateStartTime = 0;

//Arm leftArm(LEFT_INNER_ARM, LEFT_OUTER_ARM, LEFT_CLAW);
//Arm rightArm(RIGHT_INNER_ARM, RIGHT_OUTER_ARM, RIGHT_CLAW);

// Possible arm positions.
ArmPosition armsFoldedIn(CLAW_CLOSED, INNER_CLOSED, OUTER_CLOSED);
ArmPosition elbowsOpen(CLAW_CLOSED, INNER_OPEN, OUTER_CLOSED);
ArmPosition armsPreppedToDrop(CLAW_CLOSED, INNER_OPEN, OUTER_OPEN);
ArmPosition clawsOpened(CLAW_OPEN, INNER_OPEN, OUTER_OPEN);

// Change to correct configurations.
ArmPosition armsChasisDeposit(CLAW_OPEN, OUTER_CLOSED, INNER_CLOSED);
ArmPosition armsPickupFromArm(CLAW_OPEN, OUTER_CLOSED, INNER_CLOSED);
ArmPosition lastPickupSetup(CLAW_OPEN, OUTER_CLOSED, INNER_CLOSED);
ArmPosition lastPickup(CLAW_OPEN, OUTER_CLOSED, INNER_CLOSED);

// Kicker
Kicker kicker(KICKER);

// Mousetraps
Mousetrap leftMousetrap(LEFT_MOUSETRAP);
Mousetrap rightMousetrap(RIGHT_MOUSETRAP);

// TODO: Evaluate need for this function.
void goToState(int targetState) {
  state = targetState;
  Serial.println(state);
  stateStartTime = millis();
}
void resetByButton(){
  if(digitalRead(BUTTON2) == LOW){
    goToState(0);
  }
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

  pinMode(FRONT_SENSOR, INPUT);

  runStartTime = millis();
}

void loop() {
  int sensor = analogRead(FRONT_SENSOR);
  resetByButton();
  Serial.println(sensor);
  switch (state) {
    case 0:
      wheels::brake();
      kicker.kick();
      leftMousetrap.deploy();
      rightMousetrap.deploy();
      if (digitalRead(BUTTON1) == LOW){
        runStartTime = millis();
        goToState(1);
      }
      break;
      
    // First island
    case 1:
      wheels::goForward(FULL_SPEED);
      leftMousetrap.deposit();
      rightMousetrap.deposit();
      kicker.getReady();
      
      if (sensor < 700) {
        goToState(2);
      }
      break;

    case 2:
      kicker.kick();
      if (sensor > 800) {
        goToState(3);
      }
      break;

    case 3:
      if (sensor < 700) {
        goToState(4);
      }
      break;
      
    case 4:
      if (sensor > 900) {
        goToState(5);
      }
      break;
      
    // Second island
    case 5:
      wheels::goForward(FULL_SPEED);
      kicker.getReady();
      if (sensor < 700) {
        goToState(6);
      }
      break;

    case 6:
      kicker.kick();
      if (sensor > 800) {
        goToState(7);
      }
      break;

    case 7:    
      
      if (sensor < 700) {
        goToState(8);
      }
      break;
      
    case 8:
      if (sensor > 900) {
        goToState(9);
      }
      break;
      
    case 9:
      if (sensor < 800) {
        goToState(10);
      }
      break;

    case 10:
      wheels::goBackward(FULL_SPEED);
      if (millis() - stateStartTime > 10000) {
        wheels::brake();
        goToState(0);
      }
      break;
  }
}


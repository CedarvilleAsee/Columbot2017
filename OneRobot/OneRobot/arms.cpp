#include "constants.h"
#include "arms.h"
#include <Arduino.h>
#include <Servo.h>

void arms::initialize(Arm leftArm, Arm rightArm) {
  //sets up all arm servors
  leftArm.inner.attach(LEFT_INNER_ARM);
  leftArm.outer.attach(LEFT_OUTER_ARM);
  leftArm.claw.attach(LEFT_CLAW);
  rightArm.inner.attach(RIGHT_INNER_ARM);
  rightArm.outer.attach(RIGHT_OUTER_ARM);
  rightArm.claw.attach(RIGHT_CLAW);
  
}
void arms::setArmState(Arm arm, ArmState armState){
  //sets servos pos
  arm.inner.write(armState.inner);
  arm.outer.write(armState.outer);
  arm.claw.write(armState.claw);        
}

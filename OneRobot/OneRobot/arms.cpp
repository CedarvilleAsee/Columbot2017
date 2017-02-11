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
void arms::changeArmPos(ArmState &current, ArmState ending, Arm arm, int t, int currentTime, int startTime, bool &op) {
    double timeConstant = (currentTime-startTime)/(double)t;
    arms::ArmState delta;
    delta.inner = ending.inner - current.inner;
    delta.outer = ending.outer - current.outer;
    delta.claw = ending.claw - current.claw;
    arms::ArmState newAngle;
    Serial.println("Running changeArmPos");
    if(delta.inner<5 && delta.inner>-5){
      arms::setEqual(newAngle,ending);
      op = false;
    }
    else{
      newAngle.inner = (int)(timeConstant*delta.inner+current.inner);
      newAngle.outer = (int)(timeConstant*delta.outer+current.outer);
      newAngle.claw = (int)(timeConstant*delta.claw+current.claw);
    }
    arms::setArmState(arm,newAngle);
    arms::setEqual(current,newAngle);
    
}
bool arms::isEqual(ArmState arm1, ArmState arm2){
    bool armStateEqual = true;
    if (arm1.inner != arm2.inner){
      armStateEqual = false;
    }
    if (arm1.outer != arm2.outer){
      armStateEqual = false;
    }
    if (arm1.claw != arm2.claw){
      armStateEqual = false;
    }
    return armStateEqual;
}
void arms::setEqual(ArmState &arm1, ArmState arm2){
  arm1.inner = arm2.inner;
  arm1.outer = arm2.outer;
  arm1.claw  = arm2.claw;
}

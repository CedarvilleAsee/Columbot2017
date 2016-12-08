#ifndef ARMS_H
#define ARMS_H
#include <Arduino.h>
#include <Servo.h>


namespace arms {

   struct ArmState {
      //ArmState refers to the pos of the servor
      int inner;
      int outer;
      int claw;
   };

   struct Arm {
    //Arm refers to the servo 
    Servo inner;
    Servo outer;
    Servo claw;
   };

   
  //initailize sets up the servos
   void initialize(Arm leftArm, Arm rightArm);
  //setArmState sets the servos to the appropriate angles
   void setArmState(Arm arm, ArmState armState);

   

}
#endif

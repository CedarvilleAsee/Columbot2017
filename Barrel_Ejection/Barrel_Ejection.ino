/*
 Editted :2017 ASEE Programming Team
 Date:9/10/16 9/17/16
 Purpose:Initiate and begin the design of the servo
*/

#include <Servo.h>

Servo barrelDispenserServo;  // create servo object to control a servo



//declaration of constants
#define CLOSED_POS 110
#define OPEN_POS 40
#define HATCH_OPEN_SPEED 10  //increase to make faster
#define HATCH_CLOSE_SPEED 10 //increase to make faster
#define HATCH_OPEN_DELAY 400 //decrease to make faster
#define HATCH_CLOSE_DELAY 400//decrease to make faster
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {  //loop will always run
   for(int i = 0; i<3; i++){  //for loop will run 3 times in every loop
    ejectBarrel();
   }
   exit(1);//ends loop
}

void openHatch() {  //will launch the barrel
  int currentServoPos = CLOSED_POS; //starts at closed
  while (currentServoPos > OPEN_POS) {
    currentServoPos -= HATCH_OPEN_SPEED;
    myservo.write( currentServoPos );
    delay(15);
  }
}

void closeHatch() {  // will reload for the next barrel
  int currentServoPos = OPEN_POS; //starts at open
  while (currentServoPos < CLOSED_POS){
    currentServoPos += HATCH_CLOSE_SPEED;
    myservo.write( currentServoPos );
    delay(15);
  }
}

void ejectBarrel(){ //consolidation function
  openHatch();
  delay(HATCH_OPEN_DELAY);
  closeHatch();
  delay(HATCH_CLOSE_DELAY);
}


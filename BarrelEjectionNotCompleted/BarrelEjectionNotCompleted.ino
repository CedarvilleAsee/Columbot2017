/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
 Editted :Philip White and Donald Shade
 Date:9/10/16
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

// int potpin = 0;  // analog pin used to connect the potentiometer

//declaration of varilbles/constants
#define CLOSED_POS 175
#define OPEN_POS 10
#define HATCH_OPEN_SPEED 5
#define HATCH_CLOSE_SPEED 5
#define HATCH_OPEN_DELAY 1000
#define HATCH_CLOSE_DELAY 1000
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  ejectBarrel();
}

void openHatch() {
  int currentServoPos = CLOSED_POS; //starts at closed
  while (currentServoPos > OPEN_POS) {
    currentServoPos -= HATCH_OPEN_SPEED;
    myservo.write( currentServoPos );
    delay(15);
  }
}

void closeHatch() {
  int currentServoPos = OPEN_POS; //starts at open
  while (currentServoPos < CLOSED_POS){
    currentServoPos += HATCH_CLOSE_SPEED;
    myservo.write( currentServoPos );
    delay(15);
  }
}

void ejectBarrel(){
  openHatch();
  delay(HATCH_OPEN_DELAY);
  closeHatch();
  delay(HATCH_CLOSE_DELAY);
}


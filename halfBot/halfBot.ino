#include <Servo.h>
//#include <lineFollow.h>
#include "pinNumbers.h"
#include "constants.h"
#include "wheels.h"

using namespace wheels;

Servo bedMotor;
Servo kicker;

long lastTime = 0;
int driveSpeed = SPEED;
int pathCounter = 0;
int stateCounter = 0; //_NEW
int dropCounter = 0; //_NEW

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < NUM_OF_SENSORS; ++i) {
        pinMode(LINE_SENSOR_PINS[i], INPUT);
  }

  
    //LEDs on shield
    pinMode(LEDG, OUTPUT);
    pinMode(LEDR, OUTPUT);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, HIGH);
  
    //setup bed servo and point it straight
    bedMotor.attach(9);
    //bedMotor.write(90);

    //Setup the kicker
    kicker.attach(10);
    kicker.write(90);

   //setup ring arm servo
    //ringServo.attach(RING_DISPENSER_SERVO);
    //ringServo.write(0);

    //start serial communication
    //prt.begin(115200);

    //setup driving motor speed pins
    pinMode(PWMR, OUTPUT);
    pinMode(PWML, OUTPUT);
    analogWrite(PWMR, 0);
    analogWrite(PWML, 0);
    
    //tell back left motor to drive forward
    pinMode(WHEEL_DIR_BL_F, OUTPUT);
    pinMode(WHEEL_DIR_BL_B, OUTPUT);
    digitalWrite(WHEEL_DIR_BL_F, HIGH);
    digitalWrite(WHEEL_DIR_BL_B, LOW);
    
    //tell back right motor to drive forward
    pinMode(WHEEL_DIR_BR_F, OUTPUT);
    pinMode(WHEEL_DIR_BR_B, OUTPUT);
    digitalWrite(WHEEL_DIR_BR_F, HIGH);
    digitalWrite(WHEEL_DIR_BR_B, LOW);
    
    //enable driving motor controller
    pinMode(WHEEL_PWM_B_STBY, OUTPUT);
    digitalWrite(WHEEL_PWM_B_STBY, HIGH);

    //misc line sensor pin that does not get init in contructor for some reason
    //pinMode(39, INPUT);
    pinMode(11, INPUT);
    pinMode(53, INPUT);

    
    //pinMode(BUTTON1, INPUT_PULLUP);
    //pinMode(BUTTON2, INPUT_PULLUP);
    //while(digitalRead(BUTTON1));

   

}

void loop() {
  // put your main code here, to run repeatedly:

  //write the servo to increment am angle.
  for(int i = 0; i < 91; i++){
    bedMotor.write(i);
    delay(1);
  }
  
    
}

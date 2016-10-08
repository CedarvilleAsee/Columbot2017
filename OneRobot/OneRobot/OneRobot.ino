#include <Servo.h>
//#include <lineFollow.h>
#include "pinNumbers.h"
#include "constants.h"
#include "wheels.h"

using namespace wheels;

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
  
    //setup steering servo and point it straight
    //steeringMotor.attach(STEERING_PIN);
    //steeringMotor.write(NOSE_CENTER);

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


    //setup ring dispensing motor
    //pinMode(WHEEL_PWM_FR, OUTPUT);
    //analogWrite(WHEEL_PWM_FR, 0);
    //pinMode(WHEEL_DIR_BR_F, OUTPUT);
    //digitalWrite(WHEEL_DIR_FR_B, HIGH);
    //digitalWrite(WHEEL_DIR_FR_F, LOW);
    
    //enable ring dispensing motor controller
    //pinMode(WHEEL_PWM_R_STBY, OUTPUT);
    //digitalWrite(WHEEL_PWM_R_STBY, HIGH);

    //misc line sensor pin that does not get init in contructor for some reason
    //pinMode(39, INPUT);
    pinMode(11, INPUT);
    pinMode(53, INPUT);

    /*
    //setup wall sensors
    pinMode(WALL_SENSOR_R, INPUT);
    pinMode(WALL_SENSOR_RS, INPUT);
    pinMode(GARAGE_SENSOR, INPUT);
    */

    /*
    //can be used for version number to make sure new code is uploaded
    #ifdef DEBUG
    prt.println("1");
    #endif
    */
    
    //pinMode(BUTTON1, INPUT_PULLUP);
    //pinMode(BUTTON2, INPUT_PULLUP);
    //while(digitalRead(BUTTON1));

    /*
    long t = millis();
    bool toggle = false;
    while(analogRead(A8) > 400) { //Wait for light to go out
        if(millis() - t > 100) {
            if(toggle) {
                digitalWrite(LEDG, HIGH);
            } else {
                digitalWrite(LEDG, LOW);
            }
            
            t = millis();
            toggle = !toggle;
        }
    }*/
    
    /*
    setNose(NOSE_CENTER + 30);//drop nose
    delay(200);
    for(int i = 0; i < 100; ++i) {
        ringServo.write(i);
        delay(5);
    }*/
    
    
    
    
    //setNose(NOSE_CENTER - 10);
     //delay(100);
    
    //Go forward for 2/10 of a second
    driveWheels(150, 150);
    delay(50000);
    //STOPIT();
    //lastangle = NOSE_CENTER + 3;
    //setNose(NOSE_CENTER-5);
    //ringServo.write(0);
   

}

void loop() {
  // put your main code here, to run repeatedly:

  // line sensor pins
    
}

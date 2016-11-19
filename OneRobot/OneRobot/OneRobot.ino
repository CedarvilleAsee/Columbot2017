#include <Servo.h>
//#include <lineFollow.h>
#include "pinNumbers.h"
#include "constants.h"
#include "wheels.h"

using namespace wheels;

Servo firstServe;
Servo secondServe;
Servo thridServe;
Servo fourthServe;
Servo fifthServe;
Servo sixthServe;
Servo seventhServe;
Servo eightServe;
Servo ninthServe;


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

  wheels::initialize();
  
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

    //Test code for out put

    wheels::powerWheel(FrontRight, Forward, 100);



    //setNose(NOSE_CENTER - 10);
     //delay(100);

    //Go forward for 2/10 of a second
    //driveWheels(100, 100);
    delay(100000);
    //STOPIT();
    //lastangle = NOSE_CENTER + 3;
    //setNose(NOSE_CENTER-5);
    //ringServo.write(0);


}

void loop() {
  // put your main code here, to run repeatedly:

  // line sensor pins

}

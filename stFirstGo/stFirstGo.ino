#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
 // myservo.attach(PB1);
 myservo.attach(PB0);
 pinMode(PB4, INPUT_PULLUP);//for button
 pinMode(PC13, OUTPUT);
 pinMode(PA15, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(PA15) == HIGH){
     myservo.write(100);
    delay(100);
  }
  else{
    myservo.write(10);
    delay(100);
  }




}

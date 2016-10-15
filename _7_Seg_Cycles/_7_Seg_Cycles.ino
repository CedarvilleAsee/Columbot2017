#include <SoftwareSerial.h>

SoftwareSerial Serial7Segment(17, 16); //RX pin, TX pin

int cycles = 0;

void setup() {
  

  //Serial.begin(9600);
 // Serial.println("OpenSegment Example Code");
  

  Serial7Segment.begin(9600); //Talk to the Serial7Segment at 9600 bps
  Serial7Segment.write('v'); //Reset the display - this forces the cursor to return to the beginning of the display
  Serial7Segment.write(0x7a);
  Serial7Segment.write(0xff);
  
}

void loop() 
{
  cycles++; //Counting cycles! Yay!
  Serial.print("Cycle: ");
  Serial.println(cycles);
  
  char tempString[10]; //Used for sprintf
  sprintf(tempString, "%4d", cycles); //Convert deciSecond into a string that is right adjusted
  //sprintf(tempString, "%d", cycles); //Convert deciSecond into a string that is left adjusted (requires digit 1 command)
  //sprintf(tempString, "%04d", cycles); //Convert deciSecond into a string with leading zeros
  //sprintf(tempString, "%4X", cycles); //Count in HEX, right adjusted
  //int negativeCycles = cycles * -1;
  //sprintf(tempString, "%4d", negativeCycles); //Shows a negative sign infront of right adjusted number

  //Note: This method works well as long as your number is less than or equal to 4 digits.
  //14422 will cause the display to wrap (5 digits)
  //-5766 will cause the display to wrap (5 digits)
  //To fix this, send a 'v' character or look at how to control the digit placement
  //https://github.com/sparkfun/Serial7SegmentDisplay/wiki/Basic-Usage#wiki-cursor

  Serial7Segment.print(tempString); //Send serial string out the soft serial port to the S7S

  delay(1000);
}



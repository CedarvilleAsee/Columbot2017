

int cycles = 0;

void setup() {

cycles = 0;

  Serial.begin(14400); //Talk to the Serial7Segment at 9600 bps
  Serial2.begin(14400);
  Serial2.write('v'); //Reset the display - this forces the cursor to return to the beginning of the display
  Serial2.write(0x7a);
  Serial2.write(0xff);
  
}

void loop() 
{
  cycles++; //Counting cycles! Yay!
  
  
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

  //Serial2.print(tempString); //Send serial string out the soft serial port to the S7S

  if (cycles % 10000 == 0) {  
    char tempString[10]; //Used for sprintf
    sprintf(tempString, "%4d", cycles / 10000);  
    Serial2.print(tempString); 
  }
  
}


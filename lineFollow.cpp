#include "lineFollow.h"


 int getnumPinsOnLine(){
    return numPinsOnLine
  }
  
  bool* getisSensorsOnLine(){
    return isSensorsOnLine;
 }

  void update(){
    numOfSensorsOnLine = 0;
    for(int i = 0; i < NUM_OF_SENSORS - 1; i++){
      if(LINE_SENSOR_PINS[i]){
        numOfSensorsOnLine++;
        isSensorsOnLine[i] = true;
      }
    }
  }
   
  
lineSensor(){
  numSensorsOnLine = 0;
  for(int i = 1; i < NUM_OF_SENSORS; i++ ){
     isSensorsOnLine[i] = false; 
  }
}


turn steer(){
 switch(steerMode){
  case straight:

    break;
  case slightRight:
  case right:
    break;

  case slightLeft:
  case left:

    break;


  


      
 }
  
}



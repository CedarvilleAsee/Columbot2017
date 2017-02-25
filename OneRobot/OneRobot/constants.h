#ifndef CONSTANTS

#define CONSTANTS

#include "pinNumbers.h"

const int NUM_OF_SENSORS = 8;


//Constant speed
const int SPEED = 210; //Between 0-255

static const int LINE_SENSOR_PINS[NUM_OF_SENSORS] = {LINE_SENSOR_0, LINE_SENSOR_1,LINE_SENSOR_2,
  LINE_SENSOR_3, LINE_SENSOR_4, LINE_SENSOR_5, LINE_SENSOR_6, LINE_SENSOR_7};

//Arm servo constants

const int CLAW_OPEN = 95;
const int CLAW_CLOSED = 73;
const int OUTER_OPEN = 45;
const int OUTER_CLOSED = 180;
const int INNER_OPEN = 95;
const int INNER_CLOSED = 180;

//const int OPEN = 79;
//const int CLOSED = 67;
//const int CLAW = 67;
//const int ARM = 65;

//const int ARMSTATE_CLOSED = 10;
//const int ARMSTATE_PREPED = 11;
//const int ARMSTATE_STRAIGHTARM = 20;
//const int ARMSTATE_BARRELDROP = 21;


//enum turn { straight, left, right, slightLeft, slightRight}


#endif 

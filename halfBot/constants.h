#ifndef CONSTANTS

#define CONSTANTS

#include "pinNumbers.h"

const int NUM_OF_SENSORS = 8;


//Constant speed
const int SPEED = 210; //Between 0-255

const int PWMR = WHEEL_PWM_BR;
const int PWML = WHEEL_PWM_BL;

static const int LINE_SENSOR_PINS[NUM_OF_SENSORS] = {LINE_SENSOR_0, LINE_SENSOR_1,LINE_SENSOR_2,
  LINE_SENSOR_3, LINE_SENSOR_4, LINE_SENSOR_5, LINE_SENSOR_6, LINE_SENSOR_7};








//enum turn { straight, left, right, slightLeft, slightRight}


#endif 

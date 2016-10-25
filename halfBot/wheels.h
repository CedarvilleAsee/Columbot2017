#ifndef WHEELS_H
#define WHEELS_H
#include <Arduino.h>
#include <Servo.h>

namespace wheels {
  

	// description: drives the motors
	// speed: max speed of the motors
	// angle: angle of nose
	//	 0: straight
	//	>0: turning left
	//	<0: turning right
	void drive(int angle, int speed);


	// description: returns the ratio between the speeds at which
	//		the two motors should be driven
	// angle: angle of nose
	//	 0: straight
	//	>0: turning left
	//	<0: turning right
	// return: ratio between two motor speeds (left/right)
	double ratio(int angle);

	// drives wheels forwards and backwards; > 0 is forwards
	void driveWheels(int left, int right);

	// stops robot from driving and spin locks; NEVER RETURNS
	void STOPIT();

}

#endif

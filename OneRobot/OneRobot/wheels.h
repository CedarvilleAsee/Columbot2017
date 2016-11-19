#ifndef WHEELS_H
#define WHEELS_H


namespace wheels {

  enum Wheel {
    FrontRight,
    BackRight,
    FrontLeft,
    BackLeft
  };

  enum WheelDirection {
    Forward,
    Backward,
    Coast,
    Brake
  };

  // Set up all the pins for the wheels. Should be called be for any other methods
  // involving wheels.
  void initialize();

  // Power a specific wheel in a certain direction and speed.
  // Note that when the direction is Coast or Brake, the speed parameter is ignored.
  void powerWheel(Wheel wheel, WheelDirection direction,  int speed);

  // Power all four wheels to the same speed and direction.
  // Note that when the direction is Coast or Brake, the speed parameter is ignored.
  void powerAllWheels(WheelDirection direction, int speed);

  // Convenience method for stop the robot.
  void stopAllWheels();

	// description: drives the motors
	// speed: max speed of the motors
	// angle: angle of nose
	//	 0: straight
	//	>0: turning left
	//	<0: turning right
	//void drive(int angle, int speed);

	// description: returns the ratio between the speeds at which
	//		the two motors should be driven
	// angle: angle of nose
	//	 0: straight
	//	>0: turning left
	//	<0: turning right
	// return: ratio between two motor speeds (left/right)
	//double ratio(int angle);

	// drives wheels forwards and backwards; > 0 is forwards
	//void driveWheels(int left, int right);

	// stops robot from driving and spin locks; NEVER RETURNS
	//void STOPIT();

}

#endif

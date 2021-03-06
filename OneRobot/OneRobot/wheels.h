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

  // Convenience method for moving the robot.
  void brake();

  void goForward(int speed);

  void goBackward(int speed);
}

#endif

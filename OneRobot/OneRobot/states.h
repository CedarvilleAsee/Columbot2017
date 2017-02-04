#ifndef STATES_H
#define STATES_H

#include "wheels.h"
#include "arms.h"

namespace states {

  const int InitialDrive = 0;
  const int DropFirstBarrels = 1;
  const int PickupFirstBarrels = 2;
  const int LoadLeftBarrel = 3;
  const int LoadRightBarrel = 4;
  const int PrepForDrop = 5;
  const int DropLastBarrels = 6;
  const int PrepForLastPickup = 7;
  const int PickupLastBarrels = 8;

  const int Waiting = 0;
  const int FirstWall = 1;
  const int SecondWall = 2;
  const int ThirdWall = 3;
  const int FourthWall = 4;

  int currentState = InitialDrive;
  int mouseTrapState = Waiting;

  void mainMachine() {
    switch(currentState) {
      case InitialDrive:
      wheels::powerAllWheels(wheels::Forward, 100);
      break;
      case DropFirstBarrels:
      break;
    }
  }
}

#endif

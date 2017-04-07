#ifndef CONSTANTS
#define CONSTANTS

// Arm servo angles.

const int CLAW_OPEN = 50;
const int CLAW_CLOSED = 73;
const int OUTER_OPEN = 45;
const int OUTER_CLOSED = 180;
const int INNER_OPEN = 95;
const int INNER_CLOSED = 180;

// Kicker angles
const int KICKER_READY = 70;
const int KICKER_KICKED = 100;

// Dumper angle
const int DUMPER_DUMPED = 45;

// Mousetrap positions
const int MOUSETRAP_DEPLOYED = 0;
const int MOUSETRAP_DEPOSITED = 45;

// Speed levels

const int FULL_SPEED = 70;
const int HALF_SPEED = 70;
const int SLOW_SPEED = 50;

// Sensor threshold
const int CLAW_SENSOR_THRESHOLD = 100;
const int BACKWALL_SENSOR_THRESHOLD = 100;
const int ISLAND_SENSOR_THRESHOLD = 100;
const int FRONTWALL_SENSOR_THRESHOLD = 100;

#endif

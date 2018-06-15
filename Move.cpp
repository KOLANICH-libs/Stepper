#include "Stepper.h"
#include "bcm2835.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	// Print usage
  if (argc != 4)
  {
    std::cerr << "usage: Move speed maxSteps steps" << endl;
    return 1;
  }
  // Initialize stepper on pins 27, 22, 23, & 24
  Stepper motor(argv[2], 27, 22, 23, 24);
  // Set the speed
  motor.setSpeed(argv[1]);
  // Step the motor
  motor.step(atoi(argv[3]));
}

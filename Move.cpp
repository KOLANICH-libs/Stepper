#include "Stepper.h"
#include "bcm2835.h"
#include <unistd.h>
#include <iostream>

#define STEPS_PER_REVOLUTION 512 //512 steps per revolution

int main()
{
  // Initialize stepper on pins 27, 22, 23, & 24, with the steps per revolution
  Stepper motor(STEPS_PER_REVOLUTION, 27, 22, 23, 24);
  // Set the speed
  motor.setSpeed(50);
  std::cout << "Speed set" << std::endl;
  while (1)
  {
    // Step the motor one revolution clockwise
    std::cout << "Clockwise" << std::endl;
    motor.step(STEPS_PER_REVOLUTION);
    // Sleep to make moves independent
    usleep(500000);
    // Step the motor one revolution counterclockwise
    std::cout << "Counterclockwise" << std::endl;
    motor.step(-STEPS_PER_REVOLUTION);
    // Sleep to make moves independent
    usleep(500000);
  }
}

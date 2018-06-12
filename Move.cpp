#include "Stepper.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    std::cerr << "usage: Move speed steps" << endl;
    return 1;
  }
  Stepper motor(800, GPIO, 27, 22, 23, 24);
  motor.setSpeed(argv[1]);
  motor.step(atoi(argv[2]));
}

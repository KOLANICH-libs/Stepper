#include <Stepper.h>

// Ensure this library description is only included once
#ifndef StepperTB6560_h
#define StepperTB6560_h

class StepperTB6560: Stepper {
  public:
    // Constructors
    Stepper(int number_of_steps, int clk_pin, int cw_pin, int en_pin);

    // Methods
    void step(int number_of_steps);
    int getTotalSteps();
    void reset();

  private:
    // Motor pin numbers
    int clk_pin;
    int cw_pin;
    int en_pin;

    // Counter of total steps done by the motor
    int total_steps;
};

#endif


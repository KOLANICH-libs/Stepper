#include "StepperTB6560.h"

/*
 *  Constructor for TB6560 Stepper Driver
 *  Sets which wires should control the motor.
 */
StepperTB6560::StepperTB6560(int number_of_steps, int clk_pin, int cw_pin, int en_pin) {
  this->step_number = 0;    // which step the motor is on
  this->direction = 0;      // motor direction
  this->last_step_time = 0; // time stamp in us of the last step taken
  this->number_of_steps = number_of_steps; // total number of steps for this motor

  // Arduino pins for the motor control connection:
  this->clk_pin = clk_pin;
  this->cw_pin = cw_pin;
  this->en_pin = en_pin;

  // setup the pins on the microcontroller:
  pinMode(this->clk_pin, OUTPUT);
  pinMode(this->cw_pin, OUTPUT);
  pinMode(this->en_pin, INPUT);

  // When there are a TB6560 stepper motor driver, set the others pins to 0:
  this->motor_pin_1 = 0;
  this->motor_pin_2 = 0;
  this->motor_pin_3 = 0;
  this->motor_pin_4 = 0;
  this->motor_pin_5 = 0;

  // pin_count is used by the stepMotor() method:
  this->pin_count = 1;
}

/*
 * Makes steps.
 * @param steps_to_move steps to done 
 */
void Stepper::step(int steps_to_move) {
  // Checks if the driver is enable or not (0 = enable, 1 = disable)
  enable = !digitalRead(en_pin);
  if (!enable) {
    int steps_left = abs(steps_to_move);  // how many steps to take

    // determine direction based on whether steps_to_mode is + or -:
    if (steps_to_move > 0) { 
      this->direction = 1;
      // motor rotate clockwise when CW is low
      digitalWrite(cw_pin, LOW);
    }
    if (steps_to_move < 0) { 
      this->direction = 0;
      // motor rotate counterclockwise when CW is high level
      digitalWrite(cw_pin, HIGH);
    }

    // decrement the number of steps, moving one step each time:
    while (steps_left > 0) {
      unsigned long now = micros();
      // move only if the appropriate delay has passed:
      if (now - this->last_step_time >= this->step_delay) {
        // get the timeStamp of when you stepped:
        this->last_step_time = now;
        // increment or decrement the step number,
        // depending on direction:
        if (this->direction == 1) {
          this->step_number++;
          if (this->step_number == this->number_of_steps) {
            this->step_number = 0;
          }
        } else {
          if (this->step_number == 0) {
            this->step_number = this->number_of_steps;
          }
          this->step_number--;
        }
        // decrement the steps left:
        steps_left--;
        // step the motor 
        stepMotor(this->step_number % 2);
      }
    }
  }

  this->total_steps = this->total_steps + steps_to_move;
}

/*
 * Moves the motor.
 * @param thisStep 0 for HIGH pulse, 1 for LOW one
 */
void StepperTB6560::stepMotor(int thisStep) {
  switch (thisStep) {
    case 0:
      digitalWrite(clk_pin, HIGH);
    break;
    case 1:
      digitalWrite(clk_pin, LOW);
    break;
  }
}

/*
 * Gets total steps done.
 * @return the number of steps done by the motor
 */
int StepperTB6560::getTotalSteps() {
  return this->total_steps;
}

/*
 * Resets total steps done.
 */
void reset() {
  this->total_steps = 0;
}

/*
 StepperTB6560 Motor Control - one revolution

 This program drives a bipolar stepper motor through a TB6560 driver.
 The driver is attached to digital pins 8 - 10 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 25 Ago. 2016
 by Claudio Pastorini

 */

#include <StepperTB6560.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 10:
StepperTB6560 myStepper(stepsPerRevolution, 8, 9, 10);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}


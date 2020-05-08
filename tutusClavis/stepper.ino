/* Copyright (C) 2020 Noel Nyback
 * Copyright (C) 2020 Ludwig Gustafsson
 * Copyright (C) 2020 Gustav Thorén
 * Copyright (C) 2020 Victor Engdahl
 * Copyright (C) 2020 Alva Johansson Staaf
 * 
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <AFMotor.h>

#define MOTOR_STEPS_ROTATION 200
#define MOTOR_NUMBER 1
#define STEP_SIZE 25 // 200/8

AF_Stepper stepper(MOTOR_STEPS_ROTATION, MOTOR_NUMBER);
int steps;

// Stepper setup.
void stepperInit()
{
  stepper.setSpeed(8);
  debugPrintln("stepper initialised.");
}

void stepperTest()
{
  steps = 0;

  for (byte i = 2; i < 9; i++) {
    stepperKey(i);
    delay(1000);
    stepperStart();
  }
}

// Step right.
void stepperRight(char steps)
{
  debugStep(steps, 'r');
  stepper.step(steps*STEP_SIZE, FORWARD, SINGLE);
}

// Step left.
void stepperLeft(int steps)
{
  debugStep(steps, 'l');
  stepper.step(steps*STEP_SIZE, BACKWARD, SINGLE);
}

// For keys 1-8.
void stepperKey(int key)
{
  key--;
  steps = key * STEP_SIZE;
  stepper.step(steps, FORWARD, SINGLE);
  stepper.release();
}

// Should run as soon as hatch is secured.
void stepperStart()
{
  stepper.step(steps, BACKWARD, SINGLE);
  stepper.release();
}

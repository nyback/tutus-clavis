/* Copyright (C) 2020 Noel Nyback
 * Copyright (C) 2020 Ludwig Gustafsson
 * Copyright (C) 2020 Gustav Thorén
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

// Stepper setup.
void stepperInit()
{
  Serial.begin(9600);
  stepper.setSpeed(8);
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

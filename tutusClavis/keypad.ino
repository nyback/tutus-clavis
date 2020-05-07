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
#include <Wire.h>
#include "SparkFun_Qwiic_Keypad_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_keypad
KEYPAD keypad1;

void keypadInit()
{
  // Sets up interrupt that triggers when a key is pressed (if INT on the keypad stands for interrupt).
  pinMode(INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), keyInput, FALLING);

  pinMode(lock, OUTPUT); //Initialize lock as output pin.
}

 char keyInput()
{
  // KEYPAD READ CODE GOES HERE. READ KEYPAD, CHECK WHERE WE ARE (WHAT SCREEN) AND SEND THE INPUT TO APPROPRIATE ROUTINE.


  keypad1.updateFIFO();  // necessary for keypad to pull button from stack to readable register
  char button = keypad1.getButton();

  if (button == -1)
  {
    Serial.println("No keypad detected");
    delay(1000);
  }
  else if (button != 0)
  {
    if (button == '#') Serial.println();
    else if (button == '*') Serial.print(" ");
    else Serial.print(button);
  }

  delay(25);

  return button;
}

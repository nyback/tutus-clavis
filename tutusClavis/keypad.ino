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

#define INT_PIN 2

#include "SparkFun_Qwiic_Keypad_Arduino_Library.h" //Click here to get the library: http://librarymanager/All#SparkFun_keypad
KEYPAD keypad1;

char keypadPressedKey;

void keypadInit()
{
  // Sets up interrupt that triggers when a key is pressed (if INT on the keypad stands for interrupt).
  pinMode(INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), keypadInput, FALLING);

  keypadPressedKey = 0; // Sets pressed key to null.

  //Här nedan är koden jag använt!!!! Kommenterade bort allt annat men sätt tillbaka om behövs //Alva ################################

//  if (keypad1.begin() == false) {
//    //Serial.println("Keypad does not appear to be connected. Please check wiring. Freezing...");
//    while (1);
//  }

  debugPrintln("keypad initialised.");
}

//char keyInput()
void keypadInput()
{
  // KEYPAD READ CODE GOES HERE. READ KEYPAD, CHECK WHERE WE ARE (WHAT SCREEN) AND SEND THE INPUT TO APPROPRIATE ROUTINE.

  // necessary for keypad to pull button from stack to readable register
  keypad1.updateFIFO();
  keypadPressedKey = keypad1.getButton();

  Serial.println(keypadPressedKey);

//  if (button == -1)
//  {
//    //For debuging
//    /*
//    Serial.println("No keypad detected");
//    delay(1000);*/
//  }
//  else if (button != 0)
//  {
//    //For debuging 
//    /*
//    if (button == '#') Serial.println();
//    else if (button == '*') Serial.print(" ");
//    else Serial.print(button);*/
//  }

  //Delay needed, otherwise I2C gets too much info
  //delay(25);

  //Return button pressed as char
  //return button;
}

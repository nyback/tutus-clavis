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

#include <Wire.h>   // Library for I2C.
#include <EEPROM.h> // Flash memory access. (permanent-memory)

#define INT_PIN 2


//byte I2C_display = 0; // this will contain I2C address for the display.
//byte I2C_keypad = 0; // this the address for the keypad.

//int addressPosition = 0; // Contains EEPROM address for stepper position.
//int addressUserTable = 1; // Address marks start of user table. The byte contains number of users.
int lock = 13; // Lock signal connected to digital 13.

// As of writing this it looks like a user will take up 14 bytes of data in memory. 
typedef struct userData
{
  byte id; // 0-255 (We can have no more than 255 users.)
  char name[9];
  word pass; // 0-65535
  byte access; // Each bit represents one key. eg: MSB=1 -> access granted to first key.
  byte options; // room for many options, for now all that is needed is admin true or false. so maybe LSB determins
};

userData *users;

//int screenCursor = 0; // Position of "writing head" on screen. 0 being top left, 9 being top right and 39 being bottom right.
char screen[40]; // This will be used by updateScreen() and written to display.

void setup()
{
  debugInit();
  stepperInit();
  // Sets up interrupt that triggers when a key is pressed (if INT on the keypad stands for interrupt).
  pinMode(INT_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INT_PIN), keyInput, FALLING);

  pinMode(lock, OUTPUT); //Initialize lock as output pin.
  
  // IF NO ADMIN RUN firstUse()
}

void loop()
{
  stepperRight(1);
  stepperLeft(2);
  mainUI();
}

void mainUI()
{
  
}

int userCreate(char *name, word pass)
{
  //return id.
}

void deleteUser(byte id) 
{
  
}

void updateUser(byte id, struct userData user)
{
  
}

void userScan()
{
  
}

void updateScreen()// Alt 1
{
  for (int i = 0; i < 40; i++) {
    writeScreen(i, screen[i]);
  }
}

void writeScreen(int cursorPosition, char c)// Alt 2
{
  // TAKES ARGS AND WRITES TO SCREEN?
}

void keyInput()
{
  // KEYPAD READ CODE GOES HERE. READ KEYPAD, CHECK WHERE WE ARE (WHAT SCREEN) AND SEND THE INPUT TO APPROPRIATE ROUTINE.
}

void openLock()
{
  // The door lock opens when calling this function. It closes after 2s, enough for the hatch to fall down.
  digitalWrite(lock, HIGH);
  delay (2000);
  digitalWrite(lock, LOW);
}

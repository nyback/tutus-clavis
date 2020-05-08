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

#include <Wire.h>   // Library for I2C.
#include <EEPROM.h> // Flash memory access. (permanent-memory)

//int screenCursor = 0; // Position of "writing head" on screen. 0 being top left, 9 being top right and 39 being bottom right.
char screen[40]; // This will be used by updateScreen() and written to display.

void setup()
{
  debugInit();
  userInit(); // For now only loads users from EEPROM.
  lockInit();
  stepperInit();
  keypadInit();
  uiInit();

// Everything below is only for testing!


  // I uncommented these because I already created and saved them to EEPROM. First time running you should probably create som users.
//  userCreate("Alexander", 5684, 0, B00101001); // Has access to key 1, 4 and 6. Is not admin.
//  userCreate("Noel", 1122, 0xFF, 17); // Has access to key number 1 and 5. Is admin. (Should be admin as long as anything but 0 is entered as third argument.)
//  userCreate("Ludwig", 1122, 0xFF, 17);
//  userCreate("Victor", 7666, 0xFF, 17);
  
  userDebug(0); // Prints out everything about user 0.
  userDebug(1);
  userDebug(2);

  stepperRight(8);

//  userOP(0); // Makes user with id 0 admin.
//  userSetUname(1, "Nyback"); // Sets uname.
//  userAuthorise(1, 3); // Gives user access to key 3. Should print access: 4;
//
//  userDebug(0);
//  userDebug(1);
//
//  // checks if user 1 has access to key first key. userAccess() should return true (1) if access is granted and false (0) if not.
//  if (userAccess(1, 1)) { 
//    debugPrintln("User 1 has access to key 1!");
//  } else {
//    debugPrintln("User 1 did not have access to key 1!");
//  }
//  if (userAccess(1, 3)) { 
//    debugPrintln("User 1 has access to key 3!");
//  } else {
//    debugPrintln("User 1 did not have access to key 3!");
//  }
//
//  userDeAuthorise(1, 3); // 
//
//  if (userAccess(1, 1)) { 
//    debugPrintln("User 1 has access to key 1!");
//  } else {
//    debugPrintln("User 1 did not have access to key 1!");
//  }
//  if (userAccess(1, 3)) { 
//    debugPrintln("User 1 has access to key 3!");
//  } else {
//    debugPrintln("User 1 did not have access to key 3!");
//  }
//
//  userDebug(0);
//  userDebug(1);
//
//  userDelete(0);
//
//  userDebug(0);
//  userDebug(1);
//  
//  userSave(); // Writes users to EEPROM.

//  stepperTest();
}

void moveToKey(int key, byte id){
 byte perm = userAccess(id, key);
  if(perm == 1){
    String acc = "Access";
    String den = "Granted";
    displayPrint(acc,0,0);
    displayPrint(den,0,1);
    gotoKey(key);
    delay(9000); // Bör ändras sen till maxtiden för den att gå till nyckel 8
    openLock();
    delay(9000);
    gotoStart(steps);
    delay(9000); // Bör ändras sen till maxtiden för den att gå till nyckel 8
  } else {
    String acc = "Access";
    String den = "Denied";
    displayPrint(acc,0,0);
    displayPrint(den,0,1);
  }
}

void loop()
{

}

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

#define MAX_USERS 30 // Do we need more than 30 users?



typedef struct userData
{
  byte id; // 0-255 (We can have no more than 255 users.)
  char uname[10];
  word pass; // 0000-9999
  byte options; // room for many options, for now all that is needed is admin true or false. so maybe LSB determins
  byte access; // Each bit represents one key. eg: MSB=1 -> access granted to first key.
};

byte userNumber; // Number of users.
struct userData users[MAX_USERS];

// Initialise the user stuff.
void userInit()
{
  userLoad(); // Load user table.
  debugPrintln("user initialised.");
}

void userDebug(byte id)
{
  Serial.print("id: ");
  Serial.println(users[id].id);

  Serial.print("uname: ");
  Serial.println(users[id].uname);

  Serial.print("pass: ");
  Serial.println(users[id].pass);

  Serial.print("options: ");
  Serial.println(users[id].options);

  Serial.print("access: ");
  Serial.println(users[id].access);
}

byte userKeyToAccess(byte key)
{
  switch(key) {
    case 1:
      return B00000001;
      break;
    case 2:
      return B00000010;
      break;
    case 3:
      return B00000100;
      break;
    case 4:
      return B00001000;
      break;
    case 5:
      return B00010000;
      break;
    case 6:
      return B00100000;
      break;
    case 7:
      return B01000000;
      break;
    case 8:
      return B10000000;
      break;
  }
  return 0;
}

// Returns 1 if user is autorised for key.
byte userAccess(byte id, byte key)
{
  if (users[id].access & userKeyToAccess(key)) {
    return 1;
  }
  return 0;
}

// Returns 255 (1111 1111) if user is admin, 0 (0000 0000) if not.
byte userAdmin(byte id)
{
  return users[id].options;
}

// Loads all users from EEPROM.
void userLoad()
{
  userNumber = EEPROM.read(0); // Loads number of users.
  for (byte i = 0; i < userNumber; i++) {
    EEPROM.get(sizeof(userData)*i+1, users[i]);
  }
}

// Saves all users to EEPROM. Perhaps after creating first user and when exiting user settings?
void userSave()
{
  EEPROM.write(0, userNumber); // Saves number of users
  for (byte i = 0; i < userNumber; i++) {
    EEPROM.put(sizeof(userData)*i+1, users[i]);
  }
}

// Wipe all user entries.
void userClean()
{
  for (byte i = 0; i < MAX_USERS; i++)
  {
    users[i].id = 0;
    strcpy(users[i].uname, "");
    users[i].pass = 0;
    users[i].options = 0;
    users[i].access = 0;
  }
  userNumber = 0;

}

// Creates new user.
void userCreate(char* uname, word pass, byte options, byte access)
{
  users[userNumber].id = userNumber;
  strcpy(users[userNumber].uname, uname);
  users[userNumber].pass = pass;
  users[userNumber].options = options;
  users[userNumber].access = access;
  
  userNumber++;
}

// Delete user by id.
void userDelete(byte id)
{
  // Deletes user from array and subs one from userNumber.
  for (byte i = id; i < userNumber; i++) {
    users[i] = users[i+1];

    // Clears info from last user.
    users[i+1].id = 0;
    strcpy(users[i+1].uname, "");
    users[i+1].pass = 0;
    users[i+1].options = 0;
    users[i+1].access = 0;
  }
}

// Change users uname.
void userSetUname(byte id, char* uname)
{
  strcpy(users[id].uname, uname);
}

char* userGetUname(byte id)
{
  return users[id].uname;
}

// Change pass.
void userSetPass(byte id, word pass)
{
  users[id].pass = pass;
}

// Returns user password.
byte userGetPass(byte id)
{
  return users[id].pass;
}

// Make admin.
void userOP(byte id)
{
  users[id].options = 0xFF;
}

// Make user admin no longer.
void userDEOP(byte id)
{
  users[id].options = 0;
}





// Gives user access to key.
void userAuthorise(byte id, byte key)
{
  users[id].access = users[id].access | userKeyToAccess(key);
}

// Takes away a users access to key.
void userDeAuthorise(byte id, byte key)
{
  users[id].access = users[id].access & (~userKeyToAccess(key));
}

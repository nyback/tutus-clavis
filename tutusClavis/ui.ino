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

//If time permits we need some way to automatically log out due to inactivity (increased safety)
//Är det ett problem att röra sig runt i programmet endast genom att kalla nya funktioner eler bör en lösning baserad på att hoppa tillbaka implementeras

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

//Sets upp the first admin if no users exist
void firstStartup()
{
  
}

//Confirms that the user wants to log out and if so logs the user out, otherwise calls 'mainMenu'
void logOut()
{
  
}

//Gives options 'Keys', 'Log out', 'Change pin' and if user is admin 'Manage users'
void mainMenu()
{

  choice=scrollableList(/*list of available options*/)
  switch(choice)
  {
    case 1:
      keysMenu();
      break;
    case 3:
      newPinMenu();
      break;
    case 4:
      //Only possible if the logged in account is an admin account
      break;
    default:
      //If chosen option is 2 or 0 it is interpretted as log out
      logOut();
      break;
  }
}

//Displays available keys##########
void keysMenu()
{
  
  //Calls stepper if chosen key is accessible

  //displays message and calls 'mainMenu' reagrdless of accessibility
}

//Asks for a new pin and then confirmitaion, upon confirmation rewrites pin
void newPinMenu();
{
  mainMenu();
}

//Takes option "headlines" as parameters and returns which option chosen (∗ returns 0)
//Displays and handles the scrolling and chosing in a list of size n
int scrollableList(/*list of option headlines*/)
{
  
}

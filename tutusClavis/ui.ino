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

//If time permits we need some way to automatically log out due to inactivity (increased safety)

//Är det ett problem att röra sig runt i programmet endast genom att kalla nya funktioner eler bör en lösning baserad på att hoppa tillbaka implementeras
//Skulle kunna ske med kod som gör att varje gång en funktion gås tillbaka till startar 'callern' om från början (Bör göras något liknande)

//Might have messed upp breaking from the while loop



//Confirms that the user wants to log out and if so logs the user out, otherwise calls 'mainMenu'
bool logOut()
{
  //if logged out return true else return false
}

//The highest function in the ui hierarchy which handles logging in
void logIn(bool firstStartup=false)
{
  if (firstStartup==true){mainMenu();}
  while (true)
  {
    //Log in handling
    //mainMenu();
  }
}


//Sets upp the first admin if no users exist
void firstStartup()
{
  //Calls 'newNameMenu' and 'newPinMenu'
  
  logIn(true);
}

//Probably using pointer shenanigans to return a correct string
char * newNameMenu()
{
  //Calling Keyboard function to get the string
//  displayPrint("Username:");
//  userName = useAlphabet();
  //Confirming name to move on
}

//Returns an array with the accessible keys
int * keyAccessMenu()
{
  
}

//Shows a message on what is missing from the user if something is missing
//Returns true if Name, pin and access are set otherwise returns false
bool finishMenu(char Name[9], word pin, int access[8])
{
  //if everything set creates new user
}

//Takes option "headlines" as parameters and returns which option chosen (∗ returns 0)
//Displays and handles the scrolling and chosing in a list of size n
int scrollableList(/*list of option headlines*/)
{
  
}

//Displays available keys##########
void keysMenu()
{
  
  //Calls stepper if chosen key is accessible

  //displays message and returns reagardless of accessibility
}

//Asks for a new pin and then confirmitaion, upon correct confirmation rewrites pin
word newPinMenu()
{
  //return confirmed pin or none
}

//Gives options 'Keys', 'Log out', 'Change pin' and if user is admin 'Manage users'
void mainMenu()
{
  int choice;
  while (true)
  {
    choice=scrollableList(/*list of available options*/);
    switch(choice)
    {
      case 1:
        keysMenu();
        break;
      case 3:
        newPinMenu();
        break;
      case 4:
        //Only possible if the logged in account is an admin account (Excactly how remains to be figured out)
        manageUsersMenu();
        break;
      default:
        //If chosen option is 2 or 0 it is interpretted as log out
        if (logOut())
          //if logged out return to 'logIn' else continue
          return;
        break;
    }
  }
}



//Handles creating a new user
void addUserMenu()
{
  //####### Or corresponding datatypes for a user
  char Name[9];
  word pin;
  byte access;
  bool Return=false;
  int choice;
  
  while (true)
  {
    choice=scrollableList(/*list of available options*/);
    switch(choice)
    {
      case 1:
        strcpy(Name, newNameMenu());
        break;
      case 2:
        pin=newPinMenu();
        break;
      case 3:
        access=keyAccessMenu();
        break;
      case 4:
        Return=finishMenu(Name, pin, access);
        break;
      default:
      //If chosen option 0 return to 'manageUsersMenu'
        Return=true;
        break;
    }
    if (Return){return;}
  }
}

void editUserMenu()
{
  
}

void deleteUserMenu()
{
  
}


//Handles the admin commands menu
void manageUsersMenu()
{
  int choice;
  while (true)
  {
    choice=scrollableList(/*list of available options*/);
    switch(choice)
    {
      case 1:
        addUserMenu();
        break;
      case 2:
        editUserMenu();
        break;
      case 3:
        deleteUserMenu();
        break;
      default:
        //If chosen option 0 return to 'mainMenu'
        return;
    }
  }
}

// ui init function.
void uiInit()
{
  debugPrintln("ui initialised.");
}

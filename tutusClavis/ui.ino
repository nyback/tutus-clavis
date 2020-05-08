/* Copyright (C) 2020 Noel Nyback
   Copyright (C) 2020 Ludwig Gustafsson
   Copyright (C) 2020 Gustav Thorén
   Copyright (C) 2020 Victor Engdahl
   Copyright (C) 2020 Alva Johansson Staaf

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

//If time permits we need some way to automatically log out due to inactivity (increased safety)

//Är det ett problem att röra sig runt i programmet endast genom att kalla nya funktioner eler bör en lösning baserad på att hoppa tillbaka implementeras
//Skulle kunna ske med kod som gör att varje gång en funktion gås tillbaka till startar 'callern' om från början (Bör göras något liknande)

byte currentUser;


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
//Displays and handles the scrolling and chosing in a list of size options
byte scrollableList(String headlines[], byte options)
{
  for (int i = 0; i < options; i++) {
    String s1;
    String s2;
    s1 = ">" + headlines[i];                                //Gjorde istället så att man scrollar och väljer enter med *. Returnerar alltså 0-längden på headlines.
    s2 = headlines[i + 1];
    if (i == options - 1) {
      s2 = " ";
    }

    displayPrint(s1, 0, 0);
    displayPrint(s2, 0, 1);

    while (true) {
      char c = keypadInput();
      if (c == '5') {
        //Serial.println("Inne i =5");
        break;
      }
      else if (c == '*') {
        //Serial.println("Inne i =*");
        displayClear();
        return i;
      }
    }
  }
}


//Displays available keys##########
void keysMenu()
{
  byte choosenKey;
  String line1="Choose  x x x x";
  String line2="a key  x x x x ";
  
  for (byte i=1; i<5; i++)
  {
    if (userAccess(currentUser, i))
    {
      line1.setCharAt(6+i*2, char(i));
    }
  }
  for (byte i=5; i<9; i++)
  {
    if (userAccess(currentUser, i))
    {
      line2.setCharAt(i*2-3, char(i));
    }
  }

  bool Return;

  while (true)
  {
    displayPrint(line1,0,0);
    displayPrint(line2,0,1);
    
    Return=moveToKey(choosenKey, currentUser);
    if (Return){return;}

  }
}

//Asks for a new pin and then confirmitaion, upon correct confirmation rewrites pin
word newPinMenu()
{
  //return confirmed pin or none
}

//Handles creating a new user
void addUserMenu()
{
  //####### Or corresponding datatypes for a user
  char Name[9];
  word pin;
  byte access;
  bool Return = false;
  byte choice;

  while (true)
  {
    choice = scrollableList(/*list of available options,*/ 4);
    switch (choice)
    {
      case 1:
        strcpy(Name, newNameMenu());
        break;
      case 2:
        pin = newPinMenu();
        break;
      case 3:
        access = keyAccessMenu();
        break;
      case 4:
        Return = finishMenu(Name, pin, access);
        break;
      default:
        //If chosen option 0 return to 'manageUsersMenu'
        Return = true;
        break;
    }
    if (Return) {
      return;
    }
  }
}

//
void editUserMenu()
{
  //Somehow need to display a list of all the users except current admin and give editting rights to choosen user
  //alternativly could display current admin as well but just not allow changes
}

//
void deleteUserMenu()
{
  //Somehow need to display a list of all the users except current admin and give editting rights to choosen user
  //alternativly could display current admin as well but just not allow changes

  //Måste hantera att den inloggade usern fortsätter vara inloggad även efter att en user har raderats
}

//Handles the admin commands menu
void manageUsersMenu()
{
  byte choice;
  while (true)
  {
    choice = scrollableList(/*list of available options,*/ 3);
    switch (choice)
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

//Confirms that the user wants to log out and if so logs the user out, otherwise calls 'mainMenu'
bool logOut()
{
  //if logged out return true else return false
}

//Gives options 'Keys', 'Log out', 'Change pin' and if user is admin 'Manage users'
void mainMenu()
{
  byte choice;
  byte options = 3;

  if (userAdmin(currentUser) == 255)
  {
    options++;
  }

  while (true)
  {
    choice = scrollableList(/*list of available options,*/ options);
    switch (choice)
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

//The highest function in the ui hierarchy which handles logging in
void logIn(bool firstStartup = false)
{
  if (firstStartup == true) {
    mainMenu();
  }
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

// ui init function.
void uiInit()
{
  //Kollar om det finns users och om det inte gör det startar firstStartup
  debugPrintln("ui initialised.");
}

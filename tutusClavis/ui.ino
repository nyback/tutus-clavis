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
String newNameMenu() {
  char ans = 0;
//  Serial.println("a");
  displayClear();
  displayPrint("Username:", 0, 0);
//  Serial.println("b");
  String userName = useAlphabet();
//  Serial.println("c");
  displayClear();
  displayPrint(userName, 0, 0);
//  Serial.println("d");
  displayPrint("Conf(#) Retry(*)", 0, 1);
  while (true) {
    ans = keypadInput();
    if (ans == '*' || ans == '#') {
      break;
    }
  }
//  Serial.println("e");

  while (ans == '*') {
    displayClear();
    displayPrint("Username:", 0, 0);
    userName = useAlphabet();
    displayClear();
    displayPrint(userName, 0, 0);
    displayPrint("Conf(#) Retry(*)", 0, 1);
    while (true) {
      ans = keypadInput();
      if ( ans == '*' || ans == '#') {
        break;
      }
    }
  }

  return userName;
}

//Returns a byte with the accessible keys represented as bits
byte keyAccessMenu()
{
  char c='x';

  String line0 = "Choose  x x x x ";
  String line1 = "keys   x x x x  ";
  byte newAccess = 0;

  while (true)
  {
    for (byte i = 1; i < 5; i++)
    {
      if (checkAccess(newAccess, i))
      {
        line0.setCharAt(6 + i * 2, char(i+48));
      }
      else 
      {
        line0.setCharAt(6 + i * 2, 'x');
      }
    }
    for (byte i = 5; i < 9; i++)
    {
      if (checkAccess(newAccess, i))
      {
        line1.setCharAt(i * 2 - 3, char(i+48));
      }
      else
      {
        line1.setCharAt(i * 2 - 3, 'x');
      }
    }
    displayClear();
    displayPrint(line0, 0, 0);
    displayPrint(line1, 0, 1);

    while (true){
      c = keypadInput();
      delay(25);
      if (c=='*' || c=='#' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8') {
        break;
      }
    }

    if (c == '#' || c=='*') {
      return newAccess;
    }
    if (c == '1')
    {
      if ((B00000001 & newAccess) == B00000001) {
        newAccess -= B00000001;
      }
      else {
        newAccess += B00000001;
      }
    }
    if (c == '2')
    {
      if ((B00000010 & newAccess) == B00000010) {
        newAccess -= B00000010;
      }
      else {
        newAccess += B00000010;
      }
    }
    if (c == '3')
    {
      if ((B00000100 & newAccess) == B00000100) {
        newAccess -= B00000100;
      }
      else {
        newAccess += B00000100;
      }
    }
    if (c == '4')
    {
      if ((B00001000 & newAccess) == B00001000) {
        newAccess -= B00001000;
      }
      else {
        newAccess += B00001000;
      }
    }
    if (c == '5')
    {
      if ((B00010000 & newAccess) == B00010000) {
        newAccess -= B00010000;
      }
      else {
        newAccess += B00010000;
      }
    }
    if (c == '6')
    {
      if ((B00100000 & newAccess) == B00100000) {
        newAccess -= B00100000;
      }
      else {
        newAccess += B00100000;
      }
    }
    if (c == '7')
    {
      if ((B01000000 & newAccess) == B01000000) {
        newAccess -= B01000000;
      }
      else {
        newAccess += B01000000;
      }
    }
    if (c == '8')
    {
      if ((B10000000 & newAccess) == B10000000) {
        newAccess -= B10000000;
      }
      else {
        newAccess += B10000000;
      }
    }
  }
  return newAccess;
}

//Shows a message on what is missing from the user if something is missing
//Returns true if Name, pin and access are set otherwise returns false
bool finishMenu(char Name[9], word pin, int access[8]) {
  //if everything set creates new user
}

//Takes option "headlines" as parameters and returns which option chosen (∗ returns 0)
//Displays and handles the scrolling and chosing in a list of size options
byte scrollableList(String headlines[], byte options) {
  Serial.println("Scr");
  boolean down = false;
  for (int i = 0; i < options; i++) {
//    if (down) {
//      if (i <= 2) {
//        i = 0;
//      }
//      else {
//        i -= 2;
//      }
//    }
//    Serial.println("w");
    down = false;
    String s1;
    String s2;
    s1 = ">" + headlines[i];                                          //Gjorde så att man kan scrolla. # används för att välja markerat alternativ i listan
    s2 = headlines[i + 1];                                            //Listan ser ut:
    if (i == options - 1) {                                           // >Markerat alternativ
      s2 = " ";                                                       // Annat alternativ
    }
//    Serial.println("x");                                              //Returnerar alternativets index i arrayen som skickas med
    displayClear();
    displayPrint(s1, 0, 0);
    displayPrint(s2, 0, 1);
//    Serial.println("t");
    while (true) {
      char c = keypadInput();
      if (c == '5') { //neråt
        break;
      }
      else if (c == '2') {//uppåt
        //down = true;

        break;
      }
      else if (c == '#') {
        displayClear();
        return i + 1;
      }
      else if (c == '*') {
        return 0;
      }
    }
  }
  return 0;
}


//Displays available keys and calls 'moveToKey'
void keysMenu() {
  byte choosenKey;
  String line0 = "Choose  x x x x";
  String line1 = "a key  x x x x ";

  for (byte i = 1; i < 5; i++)
  {
    if (userAccess(currentUser, i))
    {
      //line0.setCharAt(6 + i * 2, char(i));
      line0.setCharAt(6 + i * 2, i+48);
    }
  }
  for (byte i = 5; i < 9; i++)
  {
    if (userAccess(currentUser, i))
    {
      //line1.setCharAt(i * 2 - 3, char(i));
      line1.setCharAt(i * 2 - 3, char(i+48));
    }
  }

  bool Return;

  displayClear();
  while (true)
  {
    displayPrint(line0, 0, 0);
    displayPrint(line1, 0, 1);

    c=keypadInput();

    if (c == '#' || c == '0') {
      //loop again
    }
    else if (c == '*') {
      //go back to previous menu
      Return = true;
    }
    else if (c == '1' | c == '2' | c == '3' | c == '4' | c == '5' | c == '6' | c == '7' | c == '8'){
      //calclates the numeric value of char c
      int nyckel = (int) c;
//      Serial.println(c);

      nyckel = nyckel-48;

//     Serial.println(nyckel);
      
      choosenKey = (byte) nyckel;

      Serial.println(choosenKey);
      
      Return = moveToKey(choosenKey, currentUser);
    }
    if (Return) {
      return;
    }
  }
}

//Asks for a new pin and then confirmitaion, upon correct confirmation rewrites pin
word newPinMenu() {
  //return confirmed pin or none

  bool corr = false;
  String pass;

  while (!corr) {

    String enter = "Enter new pin";
    String confirm = "Confirm pin";

    displayClear();
    displayPrint(enter, 0, 0);

    pass = "";

    while (true) {
      char c = keypadInput();
      if (c == '0' | c == '1' | c == '2' | c == '3' | c == '4' | c == '5' | c == '6' | c == '7' | c == '8' | c == '9') {
        pass += c;
        //Serial.print(pass.length());
      }
      else if (c == '#' | pass.length() >= 16) {
        break;
      }
    }
    displayClear();
    displayPrint(confirm, 0, 0);
    String conf = "";

    while (true) {
      char c = keypadInput();
      if (c == '0' | c == '1' | c == '2' | c == '3' | c == '4' | c == '5' | c == '6' | c == '7' | c == '8' | c == '9') {
        conf += c;
      }
      else if (c == '#' | conf.length() >= 16) {
        break;
      }
    }

    if (pass == conf) {
      corr = true;
      displayClear();
      displayPrint("Pin set", 0, 0);
      delay(2000);
      displayClear();
    } else {
      corr = false;
      displayClear();
      displayPrint("Error", 0, 0);
      delay(2000);
      displayClear();
    }
  }
  
    int passI = pass.toInt();
    word passW = (word) passI;
    Serial.print("passEntered: ");
    Serial.println(passW);

//    userSetPass(currentUser, passW);
//    userSave();
  return passW;
}


//Handles creating a new user
//REWRITE SIMILLAR TO HOW FIRST STARTUP WORKS
void addUserMenu() {
  String line0 = "Enter new data";
  String line1 = "for user";

  displayClear();
  displayPrint(line0, 0, 0);
  displayPrint(line1, 0, 1);
  delay(3000);

  char Name[9];
//  Serial.println("editName");
  String test = newNameMenu();
//  Serial.println("editNameUnder");
  test.toCharArray(Name, test.length() + 1);
//  Serial.println("Uname changed");
  
  word pin = newPinMenu();
//  Serial.println("pin changed");
  
  byte access = keyAccessMenu();
//  Serial.println("pin changed");

  byte admin;
  line0="Make user admin?";
  line1="#=yes  *=no";
  displayClear();
  displayPrint(line0, 0, 0);
  displayPrint(line1, 0, 1);

  while (true) {
    char c;
    c=keypadInput();
    if (c=='#') {
      admin=255;
      break;
    }
    if (c=='*') {
      admin=0;
      break;
    }
    delay(25);
  }
  userCreate(Name, pin, admin, access);
  
  userSave();
  Serial.println("Edit");
}

//Allows for changing of a users data
void editUserMenu() {
  String line0 = "Enter new data";
  String line1 = "for user";

  displayClear();
  displayPrint(line0, 0, 0);
  displayPrint(line1, 0, 1);
  delay(3000);

  char Name[9];
//  Serial.println("editName");
  String test = newNameMenu();
//  Serial.println("editNameUnder");
  test.toCharArray(Name, test.length() + 1);
  userSetUname(currentUser, Name);
//  Serial.println("Uname changed");
  
  word pin = newPinMenu();
  userSetPass(currentUser, pin);
  Serial.print("Entered pin: ");
  Serial.println(pin);
  Serial.print("User to change: ");
  Serial.println(currentUser);
  
  byte access = keyAccessMenu();
  userAuthorise(currentUser, access);
//  Serial.println("pin changed");

  line0="Make user admin?";
  line1="#=yes  *=no";
  displayClear();
  displayPrint(line0, 0, 0);
  displayPrint(line1, 0, 0);

  while (true) {
    char c;
    c=keypadInput();
    if (c=='#') {
      userOP(currentUser);
      break;
    }
    if (c=='*') {
      userDEOP(currentUser);
      break;
    }
    delay(25);
  }
  
  userSave();
  Serial.println("Edit");
}

//Asks for confirmation and the deletes the user
void deleteUserMenu(byte id) {
  if (id<currentUser)
  {
    userDelete(id);
    userSave();
    currentUser--;
    
  }
  else
  {
    userDelete(id);
    userSave();
  }
  //resetFunc();
  //digitalWrite(7, LOW);
  return;
}

//Gives a list of registered users and calls 'editUserMenu' or 'deleteUserMenu'
void accessUserMenu(byte function) {
  byte amountOfUsers;
  amountOfUsers=numberOfUsers();
  String users[amountOfUsers];
  byte choice;
  byte loggedInUser;
  
  for (byte i=0; i<amountOfUsers; i++)
  {
    users[i]=userGetUname(i);
  }
  
  while (true)
  {
    choice = scrollableList(users, amountOfUsers);

    if (choice-1 == currentUser)
    {
      String line0="You cannot";
      String line1="choose yourself";
      displayClear();
      displayPrint(line0,0,0);
      displayPrint(line1,0,1);
      delay(3000);
    }
    else if (choice!=0)
    {
      if (function==0) {
        loggedInUser=currentUser;
        currentUser=choice-1;
        Serial.println("innan edit user menu");
        editUserMenu();
        userSave();
        currentUser=loggedInUser;
      }
      else {
        deleteUserMenu(choice-1);
        amountOfUsers--;
        reduceUsers();
      }
    }
    else    //if input = '*' return
    {
      return;
    }
  }
}

//Handles the admin commands menu
void manageUsersMenu() {
  byte choice;
  String headlines[3];
  Serial.println("i");

  headlines[0] = "Add user";
  headlines[1] = "Edit user";
  headlines[2] = "Delete user";
  while (true)
  {
    choice = scrollableList(headlines, 3);
    switch (choice)
    {
      case 1:
        addUserMenu();
        break;
      case 2:
        Serial.println("inne i andra alt");
        accessUserMenu(0);
        break;
      case 3:
        accessUserMenu(1);
        break;
      default:
        //If chosen option 0 return to 'mainMenu'
        return;
    }
  }
}

//Confirms that the user wants to log out and if so logs the user out, otherwise calls 'mainMenu'
bool logOut() {
  //if logged out return true else return false
}

//Gives options 'Keys', 'Log out', 'Change pin' and if user is admin 'Manage users'
void mainMenu() {
  byte choice;
  byte options = 3;
  String headlines[4];

  headlines[0] = "Keys";
  headlines[1] = "Log out";
  headlines[2] = "Change pin";

  if (userAdmin(currentUser) == 255)
  {
    options++;
    headlines[3] = "Manage users";
  }

  while (true)
  {
    choice = scrollableList(headlines, options);
    Serial.print("choice: ");
    Serial.println(choice);
//    switch (choice)
//    {
//      case 1:
//        keysMenu();
//        break;
//      case 2:
//        displayClear();
//        displayPrint("Logging off",0,0);
//        delay(1500);
//        return;   
//      case 3:
//        //delay(5000);
//        word pass = newPinMenu();
//
//        delay(1000);
//        userSetPass(currentUser, pass);
//        userSave();
//        break;
//      case 4:
//        Serial.println("before");
//        manageUsersMenu();
//        delay(1000);
//        Serial.println("efter");
//        break;
//      default:
//        //If chosen option is 2 or 0 it is interpretted as log out
//        if (logOut()){
//          return;
//        }
//        break;
//        
//    }

    if (choice == 1){
      keysMenu();
    } else if (choice == 2){
      displayClear();
      displayPrint("Logging off",0,0);
      delay(1500);
      return;  
    } else if (choice == 3){
       word pass = newPinMenu();

       delay(1000);
       userSetPass(currentUser, pass);
       userSave();
    } else if (choice == 4){
      Serial.println("before");
       manageUsersMenu();
       delay(1000);
       Serial.println("efter");
    } else {
      if (logOut()){
          return;
        }
    }

  }
}

//The highest function in the ui hierarchy which handles logging in
void logIn(bool firstStartup = false) {
  //userDebug(0);

  if (firstStartup == true) {
//    Serial.print("första");
    delay(25);
    currentUser = 0; //what
    mainMenu();
  }
  else {

    delay(500);
    
    bool corr = false;
    String pass;


    while (!corr) {
      displayClear();
      String enter = "Enter pin";
      displayPrint(enter, 0, 0);
      pass = "";

      while (true) {
        char c = keypadInput();
        //strl = sizeof pass / sizeof pass[0];
        if (c == '0' | c == '1' | c == '2' | c == '3' | c == '4' | c == '5' | c == '6' | c == '7' | c == '8' | c == '9') {
          pass += c;
        }
        else if (c == '#' | pass.length() >= 16) {
          break;
        }
      }
      displayClear();

      currentUser = userFind(pass.toInt());
      Serial.println(currentUser);
      if (currentUser == 255) {
//        Serial.println("inte correct");
        delay(25);
        displayClear();
        displayPrint("Wrong pin", 0, 0);
        delay(1500);
      }
      else {
        mainMenu();
      }


    }

  }}


//Sets upp the first admin if no users exist
void firstStartup() {
  //Calls 'newNameMenu' and 'newPinMenu'

  char Name[9];
//  Serial.println("newName");
  String test = newNameMenu();
//  Serial.println("newNameUnder");
  test.toCharArray(Name, test.length() + 1);
//  Serial.println("toChar");
  word pin = newPinMenu();
//  Serial.println("firstStart");
  userCreate(Name, pin, 0xFF, B11111111);
  userSave();
  //userDebug(0);
//  Serial.println("userCreate");
  logIn(true);
}

// ui init function.
void uiInit() {
  //Kollar om det finns users och om det inte gör det startar firstStartup
//  pinMode(7, OUTPUT);
//  digitalWrite(7, HIGH);

//  Serial.println(numberOfUsers());
  if (numberOfUsers() == 0) {

    firstStartup();

  }
  else {
    Serial.println("inne");
    //mainMenu();
    logIn();
  }
  debugPrintln("ui initialised.");
}

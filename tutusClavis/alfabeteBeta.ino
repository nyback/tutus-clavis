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

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int column = 0;
char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int i = 0;
char c = '0';
String username;

String alphabetInit() {

  //Serial.begin(9600);
  // Set up the LCD's number of columns and rows
  //lcd.begin(16, 2);
  //keypadInit();
  Serial.println("Alpha init");
}

String useAlphabet() {
  // Uses 3 as move right, 2 as scroll up, 5 as scroll down, 1 as move left
  username = '\0';
  while (c != '#') {
    char c = keypadInput();
    if (c != -1) {
      if (c == '3') {
        username += alphabet[i];
        moveRight();
      }
      else if (c == '2') {
        scrollUp();
      }
      else if (c == '5') {
        scrollDown();
      }
      else if (c == '1') {
        moveLeft();
      }
      else if(c == '#'){
        break;
      }
    }
    if(c=='#'){
      break;
    }
    
    // Print on display
    lcd.setCursor(column, 1);
    lcd.print(alphabet[i]);
    lcd.setCursor(column, 1);

    // Turn off the cursor
    lcd.noCursor();
    delay(400);
    // Turn on the cursor
    lcd.cursor();
    delay(400);

    //Debug
    //Serial.println(username);
  }
  //Serial.println(username + alphabet[i]);
  char appendChar(alphabet[i]);
  //Serial.println(appendChar);
  username += appendChar;
  lcd.noCursor();
  /*Serial.println("slut");
  delay(25);
  Serial.println(username);*/
  
  return username;
}

void moveLeft() {
  column -= 1;
  if (column == -1) {
    column = 0;
  }
  i = 0;
  username[column] = '\0';
}

void moveRight() {
  column += 1;
  if (column == 9) {
    column = 0;
  }
  i = 0;

}

void scrollUp() {
  if (i < 26) {
    i += 1;
  }
  else {
    i = 0;
  }
}

void scrollDown() {
  if (i == 0) {
    i = 25;
  }
  else {
    i -= 1;
  }
}

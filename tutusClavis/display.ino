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

// Display related variables goes here:
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

// Display setup.
void displayInit()
{
  lcd.begin(16, 2);
  lcd.clear();
}

void displayPrint(String printThis, int column, int row){
  //column 0-15, row 0-1
  lcd.setCursor(column, row);
  lcd.print(printThis);
}

void displayClear(){
  lcd.clear();
}

void displayClearRow(int row){
  lcd.setCursor(0,row);
  lcd.print("                ");
}

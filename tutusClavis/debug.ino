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

char debug = 0;

// Init serial debugging.
void debugInit()
{
  debug = 1;
  Serial.begin(9600);
  Serial.println("debug initialised.");
  
}

void debugStep(char steps, char lr)
{
  if (debug) {
    char str[21];
    if (lr == 'l') {
      strcpy(str, "Rotating   steps left.");
    } else {
      strcpy(str, "Rotating   steps right.");
    }
    str[9] = steps+'0';
    Serial.println(str);
  }
}

void debugPrintln(char *string)
{
  if (debug) {
    Serial.println(string);
  }
}

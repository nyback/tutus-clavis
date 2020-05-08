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

int lock = 13; // Lock signal connected to digital 13.

void lockInit()
{
  pinMode(lock, OUTPUT); //Initialize lock as output pin.
  debugPrintln("lock initialised.");
}

void openLock()
{
  // The door lock opens when calling this function. It closes after 2s, enough for the hatch to fall down.
  digitalWrite(lock, HIGH);
  delay (2000);
  digitalWrite(lock, LOW);
}

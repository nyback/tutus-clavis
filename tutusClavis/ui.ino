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

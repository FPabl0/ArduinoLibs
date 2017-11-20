/*
 
 Author: Pablo Fuentes <f.pablo1@hotmail.com>
 Github page: https://github.com/FPabl0/ArduinoLibs
 
 This file is part of Simulink Lib.
 
 Simulink Lib is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 Simulink Lib is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with Simulink Lib; see the file COPYING3.  
 If not, see <http://www.gnu.org/licenses/>.
 
 */


#ifndef __SIMULINK_H
#define __SIMULINK_H

#include <Arduino.h>

/* Examples of readings ***************************
//Lee un byte de simulink y lo escribe en simulink
if(Simulink.available(sizeof(uint8_t))){
  i = Simulink.read();
  Simulink.write(i);
}

//Lee 16 bits de simulink y lo escribe en simulink
if(Simulink.available(sizeof(uint16_t))){
  i = Simulink.readU16();
  Simulink.write(i);
}

//Lee 32 bits de simulink y lo escribe en simulink
if(Simulink.available(sizeof(uint32_t))){
  i = Simulink.readU32();
  Simulink.write(i);
}
***************************************************/

class SimulinkClass{
private:
  void read(void *obj_p, size_t obj_size);
  void write(void *obj_p, size_t obj_size);
public:
  SimulinkClass();
  void begin(uint16_t baudrate);
  int available(size_t nbytes);
  int read();
  int8_t read8();
  uint16_t readU16();
  uint32_t readU32();
  void write(uint8_t n);
  void write(uint16_t& n);
  void write(uint32_t& n); 
};

extern SimulinkClass Simulink;

#endif

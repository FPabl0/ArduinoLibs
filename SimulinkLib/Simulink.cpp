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

#include "Simulink.h"
extern "C" {
#include "simulink_impl.h"
}

SimulinkClass::SimulinkClass(){
}

void SimulinkClass::begin(uint16_t baudrate){
  Serial.begin(baudrate);  
}

int SimulinkClass::available(size_t nbytes){
  return (Serial.available() > nbytes);  
}

int SimulinkClass::read(){
  return Serial.read();
}

void SimulinkClass::read(void *obj_p, size_t obj_size){
  //uint8_t *p = obj_p;
  uint8_t* p = void2int(obj_p);
  while(obj_size--){
    *p++ = read();
  }  
}

int8_t SimulinkClass::read8(){
  //uint16_t n = (read() & 0xFF) + (read() << 8);
  int8_t n;
  read(&n, sizeof(int8_t));
  return n;
}

uint16_t SimulinkClass::readU16(){
  //uint16_t n = (read() & 0xFF) + (read() << 8);
  uint16_t n;
  read(&n, sizeof(uint16_t));
  return n;
}

uint32_t SimulinkClass::readU32(){
  uint32_t n; //= read() + (read() << 8) + (read() << 16) + (read() << 24);
  read(&n, sizeof(uint32_t));
  return n;
}

void SimulinkClass::write(uint8_t n){
  Serial.write((uint8_t)n);
  Serial.write('\r');
  Serial.write('\n');
}

void SimulinkClass::write(void *obj_p, size_t obj_size){
  //uint8_t *p = obj_p;
  uint8_t* p = void2int(obj_p);
  while(obj_size--){
    Serial.write(*p++);
  } 
  Serial.write('\r');
  Serial.write('\n');
}

void SimulinkClass::write(uint16_t& n){
  write(&n, sizeof(uint16_t));  
}

void SimulinkClass::write(uint32_t& n){
  write(&n, sizeof(uint32_t)); 
}

SimulinkClass Simulink;

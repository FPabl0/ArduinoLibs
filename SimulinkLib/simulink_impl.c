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

#include "simulink_impl.h"

uint8_t* void2int(void *obj_p){
    uint8_t *p;
    p = obj_p;
    return (uint8_t*)p;
}

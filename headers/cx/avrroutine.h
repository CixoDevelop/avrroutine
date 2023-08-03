/*
 * This is the avrroutine library file. This library is designed to simplify 
 * basic operations related to AVR microcontrollers, such as timers, serial, 
 * and using pins in a way similar to Arduino. In addition to these tasks, 
 * the library also has support for basic electronic components, such as 
 * shift registers and H-bridges. Thanks to this library, you don't have to 
 * write the same thing over and over again in your AVR-based projects if you 
 * don't want to use Arduino.
 * 
 * Author: Cixo
 */

#ifndef CX_AVRROUTINE_H_INCLUDED
#define CX_AVRROUTINE_H_INCLUDED

#include <avr/io.h>
#include "avrroutine/chip.h"
#include "avrroutine/pins.h"
#include "avrroutine/shift_register.h"
#include "avrroutine/timer.h"
#include "avrroutine/serial.h"
#include "avrroutine/driver_engine.h"
#include "avrroutine/encoder.h"

#endif

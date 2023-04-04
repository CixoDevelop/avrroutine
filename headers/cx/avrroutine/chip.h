/*
 * This is the avrroutine library file. This library is designed to simplify 
 * basic operations related to AVR microcontrollers, such as timers, serial, 
 * and using pins in a way similar to Arduino. In addition to these tasks, 
 * the library also has support for basic electronic components, such as 
 * shift registers and H-bridges. Thanks to this library, you don't have to 
 * write the same thing over and over again in your AVR-based projects if you 
 * don't want to use Arduino.
 * 
 * Autor: Cixo
 */

#ifndef AVRROUTINE_CHIP_H_INCLUDED
#define AVRROUTINE_CHIP_H_INCLUDED

#include <avr/io.h>

/* This include propertly definitions for chip */

#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
#include "atmega328.h"
#endif

#if defined(__AVR_ATmega8__) || defined(__AVR_ATmega8P__)
#include "atmega8.h"
#endif

#endif

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

#ifndef AVRROUTINE_CHIP_MODEL_INCLUDED
#define AVRROUTINE_CHIP_MODEL_INCLUDED

/* For functions support */
#define ENABLE_PINS
#define ENABLE_TIMER

/* For pins support */
#define LOW_PORT &PORTB

/* Timer support */
#define TIMER_CLOCK_SOURCE TCCR1B
#define TIMER_CLOCK_START ((1 << CS11) | (1 << CS10))
#define TIMER_CLOCK_STOP 0x00
#define TIMER_PRESCALLER 64
#define TIMER_INTERRUPT_SETTINGS TIMSK
#define TIMER_ENABLE_INTERRUPT (1 << TOIE1)
#define TIMER_VALUE TCNT1
#define TIMER_TIMEOUT TIMER1_OVF_vect

/* Pin map */
#define PIN_1 0
#define PIN_2 1
#define PIN_3 2
#define PIN_4 3
#define PIN_5 IT_IS_VCC
#define PIN_6 IT_IS_GND
#define PIN_7 4
#define PIN_8 5
#define PIN_9 6
#define PIN_10 7
#define PIN_11 15
#define PIN_12 14
#define PIN_13 13
#define PIN_14 12
#define PIN_15 IT_IS_AVCC
#define PIN_16 IT_IS_AGND
#define PIN_17 11
#define PIN_18 10
#define PIN_19 9
#define PIN_20 8

#endif

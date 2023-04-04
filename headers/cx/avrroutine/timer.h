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

#ifndef AVRROUTINE_TIMER_H_INCLUDED
#define AVRROUTINE_TIMER_H_INCLUDED

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/** \typedef timer_count_t
 * This function define types that store current time in os.
 */
typedef uint16_t timer_count_t;

/** \def TIMER_CALC
 * This is useable for calc how much tick must timer count
 */
#define TIMER_CALC(X) ((uint16_t) \
    (0xFFFF - ((X) * (F_CPU / TIMER_PRESCALLER / 1000))))

/** \fn timer_enable
 * This function enable timer.
 */
void timer_enable();

/** \fn timer_set_timeout
 * This function set timer to trigger after clock count given times.
 * @param time Time to count
 */
void timer_set_timeout(timer_count_t time);

/** \fn timer_get_state
 * This function return current timer state.
 * @return Current timer state
 */
uint16_t timer_get_state();
 
#endif

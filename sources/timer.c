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

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "chip.h"

#ifdef ENABLE_TIMER

/** \fn timer_enable
 * This function enable timer.
 */
void timer_enable() {
    cli();

    TIMER_VALUE = 0x00;
    TIMER_CLOCK_SOURCE = TIMER_CLOCK_STOP;
    TIMER_INTERRUPT_SETTINGS = TIMER_ENABLE_INTERRUPT;
    
    sei();
}

/** \fn timer_set_timeout
 * This function set timer to trigger after clock count given times.
 * @param time Time to count
 */
void timer_set_timeout(timer_count_t time) {
    TIMER_VALUE = time;
    TIMER_CLOCK_SOURCE = TIMER_CLOCK_START;
}

/** \fn timer_get_state
 * This function return current timer state.
 * @return Current timer state
 */
uint16_t timer_get_state() {
    return TIMER_VALUE;
}

#endif

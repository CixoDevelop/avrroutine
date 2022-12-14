#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

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
 * @time Time to count
 */
void timer_set_timeout(timer_count_t time) {
    TIMER_VALUE = time;
    TIMER_CLOCK_SOURCE = TIMER_CLOCK_START;
}

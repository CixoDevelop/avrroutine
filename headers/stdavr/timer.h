#ifndef STDAVR_TIMER_H_INCLUDED
#define STDAVR_TIMER_H_INCLUDED

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
 * @time Time to count
 */
void timer_set_timeout(timer_count_t time);

#endif

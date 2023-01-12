#ifndef SOURCES_TIMER_H_INCLUDED
#define SOURCES_TIMER_H_INCLUDED

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/** \typedef timer_count_t
 * This function define types that store current time in os.
 */
typedef uint16_t timer_count_t;

/** \fn timer_enable
 * This function enable timer.
 */
void timer_enable();

/** \fn timer_set_timeout
 * This function set timer to trigger after clock count given times.
 * @time Time to count
 */
void timer_set_timeout(timer_count_t time);

/** \def TIMER_CALC
 * This is useable for calc how much tick must timer count
 */
#define TIMER_CALC(X) ((uint16_t) \
    ((0xFFFF - ((X) * (F_CPU / TIMER_PRESCALLER)))))

/** \def ATmega328, ATmega328P port
 * This is values to use in timer.c for microcontrollers.
 */
#if defined (__AVR_ATmega328P__) || (__AVR_ATmega328__)

/** \def TIMER_CLOCK_SOURCE 
 * This is register for choose hardware clock source for timer.
 */
#define TIMER_CLOCK_SOURCE TCCR1B

/** \def TIMER_CLOCK_START
 * This is settings for timer clock source with prescalller.
 */
#define TIMER_CLOCK_START ((1 << CS11) | (1 << CS10))

/** \def TIMER_CLOCK_STOP
 * This setting make hardware clock source is unconnected from timer.
 */
#define TIMER_CLOCK_STOP 0x00

/** \def TIMER_PRESCALLER
 * This is prescaller for this port. It is useable when calculating settings
 * for timer counter to wait time given in miliseconds.
 */
#define TIMER_PRESCALLER 8

/** \def TIMER_INTERRUPT_SETTINGS
 * This is register for enable or disable interrupt from timer.
 */
#define TIMER_INTERRUPT_SETTINGS TIMSK1

/** \def TIMER_ENABLE_INTERRUPT
 * This set flags for make interrupt when timer is overflowed.
 */
#define TIMER_ENABLE_INTERRUPT ((1 << TOIE1))

/** \def TIMER_VALUE
 * This is timer current state.
 */
#define TIMER_VALUE TCNT1

/** \def TIMER_OVERFLOW_VECTOR
 * This is interrupt vector to pass in ISR().
 */
#define TIMER_TIMEOUT _VECTOR(13)

#endif

#endif

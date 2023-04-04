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
#define ENABLE_PINCHANGE
#define ENABLE_SERIAL
#define ENABLE_TIMER

/* For pins support */
#define LOW_PCMSK &PCMSK0
#define GIMSK PCICR
#define LOW_PORT &PORTB

/* Timer support */
#define TIMER_CLOCK_SOURCE TCCR1B
#define TIMER_CLOCK_START ((1 << CS11) | (1 << CS10))
#define TIMER_CLOCK_STOP 0x00
#define TIMER_PRESCALLER 8
#define TIMER_INTERRUPT_SETTINGS TIMSK1
#define TIMER_ENABLE_INTERRUPT ((1 << TOIE1))
#define TIMER_VALUE TCNT1
#define TIMER_TIMEOUT _VECTOR(13)

/* Serial support */
#define SERIAL_DATA UDR0
#define SERIAL_STATE UCSR0A
#define SERIAL_MUTEX UDRE0
#define SERIAL_SPEED_LOW UBRR0L
#define SERIAL_SPEED_HIGH UBRR0H
#define SERIAL_CONTROL_FORMAT UCSR0C
#define SERIAL_CONTROL_ENABLE UCSR0B
#define SERIAL_ENABLE_RECEIVE (1 << RXEN0)
#define SERIAL_ENABLE_TRANSMIT (1 << TXEN0)
#define SERIAL_ENABLE_INTERRUPT (1 << RXCIE0)
#define SERIAL_STANDARD_FORMAT ((1 << USBS0) | (3 << UCSZ00))
#define SERIAL_RECEIVE_VECTOR _VECTOR(USART_RX_vect_num)

/* Pin map */
#define PIN_1 14
#define PIN_2 16
#define PIN_3 17
#define PIN_4 18
#define PIN_5 19
#define PIN_6 20
#define PIN_7 IT_IS_VCC
#define PIN_8 IT_IS_GND
#define PIN_9 6
#define PIN_10 7
#define PIN_11 21
#define PIN_12 22
#define PIN_13 23
#define PIN_14 0
#define PIN_15 1
#define PIN_16 2
#define PIN_17 3
#define PIN_18 4
#define PIN_19 5
#define PIN_20 IT_IS_VCC
#define PIN_21 IT_IS_AREF
#define PIN_22 IT_IS_GND
#define PIN_23 8
#define PIN_24 9
#define PIN_25 10
#define PIN_26 11
#define PIN_27 12
#define PIN_28 13

#endif

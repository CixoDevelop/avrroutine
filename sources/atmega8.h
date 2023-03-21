#ifndef STDAVR_CHIP_MODEL_INCLUDED
#define STDAVR_CHIP_MODEL_INCLUDED

/* For functions support */
#define ENABLE_PINS
#define ENABLE_SERIAL
#define ENABLE_TIMER

/* For pins support */
#define LOW_PORT &PORTD

/* Timer support */
#define TIMER_CLOCK_SOURCE TCCR1B
#define TIMER_CLOCK_START ((1 << CS11) | (1 << CS10))
#define TIMER_CLOCK_STOP 0x00
#define TIMER_PRESCALLER 64
#define TIMER_INTERRUPT_SETTINGS TIMSK
#define TIMER_ENABLE_INTERRUPT (1 << TOIE1)
#define TIMER_VALUE TCNT1
#define TIMER_TIMEOUT TIMER1_OVF_vect

/* Serial support */
#define SERIAL_DATA UDR
#define SERIAL_STATE UCSRA
#define SERIAL_MUTEX UDRE
#define SERIAL_SPEED_LOW UBRRL
#define SERIAL_SPEED_HIGH UBRRH
#define SERIAL_CONTROL_FORMAT UCSRC
#define SERIAL_CONTROL_ENABLE UCSRB
#define SERIAL_ENABLE_RECEIVE (1 << RXEN)
#define SERIAL_ENABLE_TRANSMIT (1 << TXEN)
#define SERIAL_ENABLE_INTERRUPT (1 << RXCIE)
#define SERIAL_STANDARD_FORMAT ((1 << USBS) | (3 << UCSZ0) | (1 << URSEL))
#define SERIAL_RECEIVE_VECTOR _VECTOR(USART_RXC_vect_num)

/* Pin map */
#define PIN_1 14
#define PIN_2 0
#define PIN_3 1
#define PIN_4 2
#define PIN_5 3
#define PIN_6 4
#define PIN_7 IT_IS_VCC
#define PIN_8 IT_IS_GND
#define PIN_9 22
#define PIN_10 23
#define PIN_11 5
#define PIN_12 6
#define PIN_13 7
#define PIN_14 16
#define PIN_15 17
#define PIN_16 18
#define PIN_17 19
#define PIN_18 20
#define PIN_19 21
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

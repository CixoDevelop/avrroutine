#include <stdbool.h>
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "serial.h"

/** \def SERIAL_RECEIVED_BUFFER_SIZE
 * Size of receive buffer. This can be changed from build command line. By
 * default buffer size is 8
 */
#ifndef SERIAL_RECEIVED_BUFFER_SIZE
#define SERIAL_RECEIVED_BUFFER_SIZE 8
#endif

/** \var serial_received_buffer
 * This buffer store data received from serial.
 */
char serial_received_buffer[SERIAL_RECEIVED_BUFFER_SIZE];

/** \var serial_received_buffer_position
 * This store current position in received buffer.
 */
uint8_t serial_received_buffer_position;

/** \var serial_received_callback
 * This var store callback for serial received interrupt.
 */
void (*serial_received_callback)();

/** \fn serial_init
 * This function initialise hardware serial with speed givern in parameter.
 * @speed Buad rate to select
 */
void serial_init(
    uint16_t speed 
) {
#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
    cli();

    serial_received_buffer_flush();
    serial_received_callback = 0x00;

    UBRR0H = (uint8_t) (speed >> 8); 
    UBRR0L = (uint8_t) (speed);
    
    UCSR0C = (1 << USBS0) | (3 << UCSZ00);
    UCSR0B = 
        (1 << RXEN0) | 
        (1 << TXEN0) |
        (1 << RXCIE0); 

    sei();
#endif
}

#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)

/** \fn serial_get_char
 * This get one char from serial hardware buffer.
 */
static inline char serial_get_char() {
    return UDR0;
}

/** \RECEIVE_ROUTINE_FOR_ATMEGA328
 * This receive single char, write it into buffer and run callback.
 */
ISR(USART_RX_vect) {
    serial_received_buffer[serial_received_buffer_position++] = (
        serial_get_char()
    );

    if (serial_received_buffer_position == SERIAL_RECEIVED_BUFFER_SIZE) {
        serial_received_buffer_position = 0x00;
    }
    
    if (serial_received_callback != 0x00) serial_received_callback();
}

#endif

/** \fn serial_received_buffer_flush
 * This function clean received buffer, and set position to first character.
 */
void serial_received_buffer_flush() {
    for (uint8_t count = 0x00; count < SERIAL_RECEIVED_BUFFER_SIZE; ++count) {
        serial_received_buffer[count] = 0x00;
    }

    serial_received_buffer_position = 0x00;
}

/** \fn serial_get_received_buffer_position
 * This function get current position in received buffer.
 */
uint8_t serial_get_received_buffer_position() {
    return serial_received_buffer_position;
}

/** \fn serial_get_received_buffer
 * This function return pointer to buffer with received data. Thia is 
 * array, that size is definied when library is building.
 */
char* serial_get_received_buffer() {
    return serial_received_buffer;
}

/** \fn serial_set_received_callback
 * This function set new callback, that had run whenever any character
 * received from serial. Callback must return void and get void parameter.
 * @(*callback)(void) New callback function
 */
void serial_set_received_callback(void (*callback)(void)) {
    serial_received_callback = callback;
}

/** \fn serial_is_writeable
 * This check that is serial port ready to send next byte. If it is ready, 
 * then return true, other way return false.
 */
bool serial_is_writeable() {
#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
    return (UCSR0A & (1 << UDRE0));
#endif
}

/** \fn serial_write_char
 * This function write on char to serial port. This not check if serial is 
 * writeable or not. Program would check it by seris_is_writeable.
 * @payload Char to write
 */
void serial_write_char(char payload) {
#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
    while (!serial_is_writeable()) ;
    UDR0 = payload;
#endif
}

/** \fn serial_write_string
 * This function write string, that mean chars from given address to nullchar.
 * @*payload String to write
 */
void serial_write_string(char *payload) {
    do {
        serial_write_char(*payload);
    } while (*(payload++) != 0x00);
}

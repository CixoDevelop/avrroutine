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

#include <stdbool.h>
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "serial.h"
#include "chip.h"

#ifdef ENABLE_SERIAL

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
 * @param speed Buad rate to select
 */
void serial_init(uint16_t speed) {
    cli();

    serial_received_buffer_flush();
    serial_received_callback = 0x00;

    SERIAL_SPEED_HIGH = (uint8_t) (speed >> 8); 
    SERIAL_SPEED_LOW = (uint8_t) (speed);
    
    SERIAL_CONTROL_FORMAT = SERIAL_STANDARD_FORMAT;
    SERIAL_CONTROL_ENABLE = 
        SERIAL_ENABLE_RECEIVE | 
        SERIAL_ENABLE_TRANSMIT |
        SERIAL_ENABLE_INTERRUPT; 

    sei();
}

/** \fn serial_get_char
 * This get one char from serial hardware buffer.
 * @return Single char in UART
 */
static inline char serial_get_char() {
    return SERIAL_DATA;
}

/** \ISR_RECEIVE_ROUTINE
 * This receive single char, write it into buffer and run callback.
 */
ISR(SERIAL_RECEIVE_VECTOR) {
    serial_received_buffer[serial_received_buffer_position++] = (
        serial_get_char()
    );

    if (serial_received_buffer_position == SERIAL_RECEIVED_BUFFER_SIZE) {
        serial_received_buffer_position = 0x00;
    }
    
    if (serial_received_callback != 0x00) serial_received_callback();
}

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
 * @return Current position in received buffer
 */
uint8_t serial_get_received_buffer_position() {
    return serial_received_buffer_position;
}

/** \fn serial_get_last_receiver
 * This function return last received char.
 * @return Last received char in buffer
 */
char serial_get_last_received() {
    uint8_t position = serial_received_buffer_position;

    if (position == 0x00) position = sizeof(serial_received_buffer);

    return serial_received_buffer[--position];
}

/** \fn serial_get_received_buffer
 * This function return pointer to buffer with received data. Thia is 
 * array, that size is definied when library is building.
 * @return Pointer to received buffer
 */
char* serial_get_received_buffer() {
    return serial_received_buffer;
}

/** \fn serial_set_received_callback
 * This function set new callback, that had run whenever any character
 * received from serial. Callback must return void and get void parameter.
 * @param (*callback)(void) New callback function
 */
void serial_set_received_callback(void (*callback)(void)) {
    serial_received_callback = callback;
}

/** \fn serial_is_writeable
 * This check that is serial port ready to send next byte. If it is ready, 
 * then return true, other way return false.
 * @return True if serial is writeable, false if not
 */
bool serial_is_writeable() {
    return (SERIAL_STATE & (1 << SERIAL_MUTEX));
}

/** \fn serial_write_char
 * This function write on char to serial port. This not check if serial is 
 * writeable or not. Program would check it by seris_is_writeable.
 * @param payload Char to write
 */
void serial_write_char(char payload) {
    while (!serial_is_writeable()) ;
    SERIAL_DATA = payload;
}

/** \fn serial_write_string
 * This function write string, that mean chars from given address to nullchar.
 * @param *payload String to write
 */
void serial_write_string(char *payload) {
    do {
        serial_write_char(*payload);
    } while (*(payload++) != 0x00);
}

#endif

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

#ifndef AVRROUTINE_SERIAL_H_INCLUDED
#define AVRROUTINE_SERIAL_H_INCLUDED

#include <stdbool.h>
#include <stdint.h>

/** \def BUADRATE
 * This is for serial_init, and it can calc value to setup.
 */
#define BUADRATE(X) (F_CPU/16/(X)-1)

/** \fn serial_init
 * This function initialise hardware serial with speed givern in parameter.
 * @param speed Buad rate to select
 */
void serial_init(uint16_t speed);

/** \fn serial_get_char
 * This get one char from serial hardware buffer.
 * @return Single char in UART
 */
char* serial_get_received_buffer();

/** \fn serial_received_buffer_flush
 * This function clean received buffer, and set position to first character.
 */
void serial_received_buffer_flush();

/** \fn serial_get_received_buffer_position
 * This function get current position in received buffer.
 * @return Current position in received buffer
 */
uint8_t serial_get_received_buffer_position();

/** \fn serial_set_received_callback
 * This function set new callback, that had run whenever any character
 * received from serial. Callback must return void and get void parameter.
 * @param (*callback)(void) New callback function
 */
void serial_set_received_callback(void (*callback)(void));

/** \fn serial_get_last_receiver
 * This function return last received char.
 * @return Last received char in buffer
 */
char serial_get_last_received();

/** \fn serial_is_writeable
 * This check that is serial port ready to send next byte. If it is ready, 
 * then return true, other way return false.
 * @return True if serial is writeable, false if not
 */
bool serial_is_writeable();

/** \fn serial_write_char
 * This function write on char to serial port. This not check if serial is 
 * writeable or not. Program would check it by seris_is_writeable.
 * @param payload Char to write
 */
void serial_write_char(char payload);

/** \fn serial_write_string
 * This function write string, that mean chars from given address to nullchar.
 * @param *payload String to write
 */
void serial_write_string(char *payload);

#endif

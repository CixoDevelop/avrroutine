#ifndef STDAVR_SERIAL_H_INCLUDED
#define STDAVR_SERIAL_H_INCLUDED

#include <stdbool.h>
#include <stdint.h>

#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)

/** \def BUADRATE_9600
 * This is for serial_init, and it is 9600 speed.
 */
#define BUADRATE_9600 F_CPU/16/9600-1 

/** \def BUADRATE_115200
 * This is for serial_init, and it is 115200 speed.
 */
#define BUADRATE_115200 F_CPU/16/115200-1

#endif

/** \fn serial_init
 * This function initialise hardware serial with speed givern in parameter.
 * @speed Buad rate to select
 */
void serial_init(
    uint16_t speed
);

/** \fn serial_get_received_buffer
 * This function return pointer to buffer with received data. Thia is 
 * array, that size is definied when library is building.
 */
char* serial_get_received_buffer();

/** \fn serial_received_buffer_flush
 * This function clean received buffer, and set position to first character.
 */
void serial_received_buffer_flush();

/** \fn serial_get_received_buffer_position
 * This function get current position in received buffer.
 */
uint8_t serial_get_received_buffer_position();

/** \fn serial_set_received_callback
 * This function set new callback, that had run whenever any character
 * received from serial. Callback must return void and get void parameter.
 * @(*callback)(void) New callback function
 */
void serial_set_received_callback(void (*callback)(void));

/** \fn serial_is_writeable
 * This check that is serial port ready to send next byte. If it is ready, 
 * then return true, other way return false.
 */
bool serial_is_writeable();

/** \fn serial_write_char
 * This function write on char to serial port. This not check if serial is 
 * writeable or not. Program would check it by seris_is_writeable.
 * @payload Char to write
 */
void serial_write_char(char payload);

/** \fn serial_write_string
 * This function write string, that mean chars from given address to nullchar.
 * @*payload String to write
 */
void serial_write_string(char *payload);

#endif

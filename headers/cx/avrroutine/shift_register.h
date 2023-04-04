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

#ifndef AVRROUTINE_SHIFT_REGISTER_H_INCLUDED
#define AVRROUTINE_SHIFT_REGISTER_H_INCLUDED

#include <stdint.h>
#include <stdbool.h>
#include "pins.h"

/** \struct shift_register_t
 * This struct store pins for shift register. It is uset to pass less params
 * into functions that working on shift register.
 */
typedef struct {
    pin_t ds;
    pin_t st;
    pin_t sh;
} shift_register_t;

/** \fn shift_register_create
 * This function create new shift register to work with it. You must pass
 * pointer to memory area when it will be stored.
 * @param *part Pointer to shift register to work on
 * @param ds DS or SER pin of register
 * @param st ST_CP or RCLK pin of register 
 * @param sh SH_CP or SRCLK pin of register
 */
void shift_register_create(
    shift_register_t *part, 
    pin_t ds, 
    pin_t st, 
    pin_t sh
);

/** \fn shift_register_send
 * This function send new data into shift register. When confirm is enable,
 * then shift register will reload latch. If not, then it is only shifted.
 * @param *part Pointer to shift register to work on
 * @param data Data to send
 * @param confirm When it is true, latch will tact, and data will be send to pins
 */
void shift_register_send(shift_register_t *part, uint8_t data, bool confirm);

#endif

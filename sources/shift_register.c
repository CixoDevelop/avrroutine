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

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "pins.h"
#include "shift_register.h"

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
) {
    part->ds = ds;
    part->st = st;
    part->sh = sh;

    pin_set_state(ds, LOW);
    pin_set_state(st, LOW);
    pin_set_state(sh, LOW);

    pin_set_mode(ds, OUTPUT);
    pin_set_mode(st, OUTPUT);
    pin_set_mode(sh, OUTPUT);
}

/** \fn shift_register_send
 * This function send new data into shift register. When confirm is enable,
 * then shift register will reload latch. If not, then it is only shifted.
 * @param *part Pointer to shift register to work on
 * @param data Data to send
 * @param confirm When it is true, latch will tact, and data will be send to pins
 */
void shift_register_send(shift_register_t *part, uint8_t data, bool confirm) {
    uint8_t ds_mask = pin_get_mask(part->ds); 
    uint8_t st_mask = pin_get_mask(part->st); 
    uint8_t sh_mask = pin_get_mask(part->sh);

    volatile uint8_t *ds_pointer = pin_get_register(part->ds, PORT);
    volatile uint8_t *st_pointer = pin_get_register(part->st, PORT);
    volatile uint8_t *sh_pointer = pin_get_register(part->sh, PORT);

    uint8_t sreg = SREG;
    cli();

    for (uint8_t bit = 8; bit > 0; --bit) {
        if (data & (1 << (bit - 1))) *ds_pointer |= ds_mask;
        else *ds_pointer &= ~ds_mask;

        *sh_pointer |= sh_mask;
        *sh_pointer &= ~sh_mask;
    }

    if (confirm) {
        *st_pointer |= st_mask;
        *st_pointer &= ~st_mask;
    }

    SREG = sreg;
}

#ifndef STDAVR_SHIFT_REGISTER_H_INCLUDED
#define STDAVR_SHIFT_REGISTER_H_INCLUDED

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
 * @*part Pointer to shift register to work on
 * @ds DS or SER pin of register
 * @st ST_CP or RCLK pin of register 
 * @sh SH_CP or SRCLK pin of register
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
 * @*part Pointer to shift register to work on
 * @data Data to send
 * @confirm When it is true, latch will tact, and data will be send to pins
 */
void shift_register_send(shift_register_t *part, uint8_t data, bool confirm);

#endif

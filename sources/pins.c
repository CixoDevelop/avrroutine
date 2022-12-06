#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "pins.h"

#ifndef LOW_PORT

#ifdef PORTA
#define LOW_PORT &PORTA
#else
#define LOW_PORT &PORTB
#endif

#endif

/** \fn pin_get_mask
 * This function create mask for pin, it is required for change pin state in 
 * port, pin or directory register.
 * @pin Pin number to work on
 */
uint8_t pin_get_mask(pin_t pin) {
    return (pin_t) (1 << (pin % 8));
}

/** \fn pin_get_register
 * This function return pointer to register for pin, with changed type. 
 * Returned pointer is used to manipulating pin state in hardware.
 * @pin Pin number to work on
 * @type Type of register
 */
volatile uint8_t* pin_get_register(pin_t pin, pin_register_t type) {
    return (volatile uint8_t *) (
        LOW_PORT - type + ((uint8_t) (pin / 8) * 3)  
    );
}

/** \fn pin_get_mode
 * This function return current mode of given pin.
 * @pin Pin number to work on
 */
pin_mode_t pin_get_mode(pin_t pin) {
    uint8_t mask = pin_get_mask(pin);
    volatile uint8_t *pointer = pin_get_register(pin, DDR);

    return (pin_mode_t) ((*pointer & mask) != 0x00);
}

/** \fn pin_get_state 
 * This function return current state of given pin.
 * @pin Pin number to work on
 */
pin_state_t pin_get_state(pin_t pin) {
    uint8_t mask = pin_get_mask(pin);
    volatile uint8_t *pointer = pin_get_register(pin, PIN);

    return (pin_state_t) ((*pointer & mask) != 0x00);
}

/** \fn pin_set_mode 
 * This functoin set new mode to given pin.
 * @pin Pin number to work on
 * @mode New mode to set 
 */
void pin_set_mode(pin_t pin, pin_mode_t mode) {
    uint8_t mask = pin_get_mask(pin);
    volatile uint8_t *pointer = pin_get_register(pin, DDR);

    uint8_t sreg = SREG;
    cli();

    if (mode == OUTPUT) *pointer |= mask;
    else *pointer &= ~mask;

    SREG = sreg;
}

/** \fn pin_set_state
 * This function set new pin state to given pin.
 * @pin Pin numbet to work on
 * @state New state of pin to set
 */
void pin_set_state(pin_t pin, pin_state_t state) {
    uint8_t mask = pin_get_mask(pin);
    volatile uint8_t *pointer = pin_get_register(pin, PORT);

    uint8_t sreg = SREG;
    cli();

    if (state == HIGH) *pointer |= mask;
    else *pointer &= ~mask;

    SREG = sreg;
}


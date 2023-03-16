#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "pins.h"
#include "chip.h"

#ifdef ENABLE_PINS
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
#endif

#ifdef ENABLE_PINCHANGE
/** \fn pin_enable_pinchange
 * This enable pinchange in the microcontroller. Warning, this clean
 * all sets to work in pinchange interrupt pins and enable interrupts
 * in microcontroller.
 */
void pin_enable_pinchange() {
    cli();

    #ifdef PCMSK0
    PCMSK0 = 0x00;
    GIMSK |= (1 << PCIE0);
    #endif

    #ifdef PCMSK1
    PCMSK1 = 0x00;
    GIMSK |= (1 << PCIE1);
    #endif

    #ifdef PCMSK2
    PCMSK2 = 0x00;
    GIMSK |= (1 << PCIE2);
    #endif

    #ifdef PCMSK3
    PCMSK3 = 0x00;
    GIMSK |= (1 << PCIE3);
    #endif

    #ifdef PCMSK4
    PCMSK4 = 0x00;
    GIMSK |= (1 << PCIE4);
    #endif

    #ifdef PCMSK5
    PCMSK5 = 0x00;
    GIMSK |= (1 << PCIE5);
    #endif

    sei();
}

/** \fn pin_set_pinchange
 * This enable pinchange on given pin.
 * @pin Pin to enable pinchange on it
 */
void pin_set_pinchange(pin_t pin) {
    volatile uint8_t *pcmask = (LOW_PCMSK) + (
		((uint8_t) (pin)) / 8
	);
    uint8_t mask = _BV (pin % 8);

    *pcmask |= mask;
}

/** \fn pin_unset_pinchange
 * This disable pinchange on given pin.
 * @pin Pin to disable pinchange on it
 */
void pin_unset_pinchange(pin_t pin) {
    volatile uint8_t *pcmask = (LOW_PCMSK) + (
		((uint8_t) (pin)) / 8
	);
    uint8_t mask = _BV (pin % 8);

    *pcmask &= ~mask;
}
#endif

#ifndef SOURCES_PINS_H_INCLUDED
#define SOURCES_PINS_H_INCLUDED

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/** \typedef pin_t
 * This type store number of microcontroller pin
 */
typedef uint8_t pin_t;

/** \typedef pin_state_t 
 * This enum store pin state, HIGH is true, LOW is false. This can be used
 * like standard bool.
 */
typedef enum {
    LOW = false,
    HIGH = true
} pin_state_t;

/** \typedef pin_mode_t 
 * This enum store pin mode, OUTPUT is true, INPUT is false. This cam be
 * used like standard bool.
 */
typedef enum {
    INPUT = false,
    OUTPUT = true
} pin_mode_t;

typedef enum {
    PORT = 0,
    DDR = 1,
    PIN = 2
} pin_register_t;

/** \fn pin_get_mask
 * This function create mask for pin, it is required for change pin state in 
 * port, pin or directory register.
 * @pin Pin number to work on
 */
uint8_t pin_get_mask(pin_t pin);

/** \fn pin_get_register
 * This function return pointer to register for pin, with changed type. 
 * Returned pointer is used to manipulating pin state in hardware.
 * @pin Pin number to work on
 * @type Type of register
 */
volatile uint8_t* pin_get_register(pin_t pin, pin_register_t type);

/** \fn pin_get_mode
 * This function return current mode of given pin.
 * @pin Pin number to work on
 */
pin_mode_t pin_get_mode(pin_t pin);

/** \fn pin_get_state 
 * This function return current state of given pin.
 * @pin Pin number to work on
 */
pin_state_t pin_get_state(pin_t pin);

/** \fn pin_set_mode 
 * This functoin set new mode to given pin.
 * @pin Pin number to work on
 * @mode New mode to set 
 */
void pin_set_mode(pin_t pin, pin_mode_t mode);

/** \fn pin_set_state
 * This function set new pin state to given pin.
 * @pin Pin numbet to work on
 * @state New state of pin to set
 */
void pin_set_state(pin_t pin, pin_state_t state);

/** \fn pin_enable_pinchange
 * This enable pinchange in the microcontroller. Warning, this clean
 * all sets to work in pinchange interrupt pins and enable interrupts
 * in microcontroller.
 */
void pin_enable_pinchange();

/** \fn pin_set_pinchange
 * This enable pinchange on given pin.
 * @pin Pin to enable pinchange on it
 */
void pin_set_pinchange(pin_t pin);

/** \fn pin_unset_pinchange
 * This disable pinchange on given pin.
 * @pin Pin to disable pinchange on it
 */
void pin_unset_pinchange(pin_t pin);

#endif

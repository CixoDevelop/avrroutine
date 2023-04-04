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

#ifndef AVRROUTINE_PINS_H_INCLUDED
#define AVRROUTINE_PINS_H_INCLUDED

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <avr/io.h>

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
 * @param pin Pin number to work on
 * @return Binary mask for pin
 */
uint8_t pin_get_mask(pin_t pin);

/** \fn pin_get_register
 * This function return pointer to register for pin, with changed type. 
 * Returned pointer is used to manipulating pin state in hardware.
 * @param pin Pin number to work on
 * @param type Type of register
 * @return Register of that pin
 */
volatile uint8_t* pin_get_register(pin_t pin, pin_register_t type);

/** \fn pin_get_mode
 * This function return current mode of given pin.
 * @param pin Pin number to work on
 * @return Current mode of pin
 */
pin_mode_t pin_get_mode(pin_t pin);

/** \fn pin_get_state 
 * This function return current state of given pin.
 * @param pin Pin number to work on
 * @return Current state of pin
 */
pin_state_t pin_get_state(pin_t pin);

/** \fn pin_set_mode 
 * This functoin set new mode to given pin.
 * @param pin Pin number to work on
 * @param mode New mode to set 
 */
void pin_set_mode(pin_t pin, pin_mode_t mode);

/** \fn pin_set_state
 * This function set new pin state to given pin.
 * @param pin Pin numbet to work on
 * @param state New state of pin to set
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
 * @param pin Pin to enable pinchange on it
 */
void pin_set_pinchange(pin_t pin);

/** \fn pin_unset_pinchange
 * This disable pinchange on given pin.
 * @param pin Pin to disable pinchange on it
 */
void pin_unset_pinchange(pin_t pin);

#endif

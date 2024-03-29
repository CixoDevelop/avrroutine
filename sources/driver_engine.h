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

#ifndef AVRROUTINE_DRIVER_ENGINE_H_DEFINED
#define AVRROUTINE_DRIVER_ENGINE_H_DEFINED

#include "pins.h"

/** \struct driver_t
 * This is type for engine h-bridge driver. It can be used to standard control
 * of the motor connected to that driver. This store all of the three pins 
 * required for control h-bridge.
 */
typedef struct {

    /* Forward pin */
    pin_t forward;

    /* Backward pin */
    pin_t backward;

    /* Enable pin */
    pin_t enable;

} driver_t;

/** \fn driver_create 
 * This function create and initiate hardware for engine driver. Must give 
 * only driver structure, forward pin, backward pin and enable pin.
 * @param *driver Driver structure to init
 * @param forward Forward pin
 * @param backward Backward pin
 * @param enable Enable pin
 */
void driver_create(
    driver_t *driver,
    pin_t forward, 
    pin_t backward, 
    pin_t enable
);

/** \fn driver_stop_engine
 * This function stop engine.
 * @param *driver Driver to stop engine connected to it
 */
void driver_stop_engine(driver_t *driver);

/** \fn driver_move_forward
 * This function start forward move on engine.
 * @param *driver Driver to move it forward
 */
void driver_move_forward(driver_t *driver);

/** \fn driver_move_backward 
 * This function make backward move on engine.
 * @param *driver Driver to make move on
 */
void driver_move_backward(driver_t *driver);

#endif

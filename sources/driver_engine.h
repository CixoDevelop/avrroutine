#ifndef STDAVR_DRIVER_ENGINE_H_DEFINED
#define STDAVR_DRIVER_ENGINE_H_DEFINED

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
 * @*driver Driver structure to init
 * @forward Forward pin
 * @backward Backward pin
 * @enable Enable pin
 */
void driver_create(
    driver_t *driver,
    pin_t forward, 
    pin_t backward, 
    pin_t enable
);

/** \fn driver_stop_engine
 * This function stop engine.
 * @*driver Driver to stop engine connected to it
 */
void driver_stop_engine(driver_t *driver);

/** \fn driver_move_forward
 * This function start forward move on engine.
 * @*driver Driver to move it forward
 */
void driver_move_forward(driver_t *driver);

/** \fn driver_move_backward 
 * This function make backward move on engine.
 * @*driver Driver to make move on
 */
void driver_move_backward(driver_t *driver);

#endif

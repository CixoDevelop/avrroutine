#include "driver_engine.h"

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
) {
    driver->forward = forward;
    driver->backward = backward;
    driver->enable = enable;

    driver_stop_engine(driver);
    
    pin_set_mode(forward, OUTPUT);
    pin_set_mode(backward, OUTPUT);
    pin_set_mode(enable, OUTPUT);
}

/** \fn driver_stop_engine
 * This function stop engine.
 * @*driver Driver to stop engine connected to it
 */
void driver_stop_engine(driver_t *driver) {
    pin_set_state(driver->enable, LOW);
    pin_set_state(driver->forward, LOW);
    pin_set_state(driver->backward, LOW);
}

/** \fn driver_move_forward
 * This function start forward move on engine.
 * @*driver Driver to move it forward
 */
void driver_move_forward(driver_t *driver) {
    pin_set_state(driver->backward, LOW);
    pin_set_state(driver->forward, HIGH);
    pin_set_state(driver->enable, HIGH);
}

/** \fn driver_move_backward 
 * This function make backward move on engine.
 * @*driver Driver to make move on
 */
void driver_move_backward(driver_t *driver) {
    pin_set_state(driver->forward, LOW);
    pin_set_state(driver->backward, HIGH);
    pin_set_state(driver->enable, HIGH);
}

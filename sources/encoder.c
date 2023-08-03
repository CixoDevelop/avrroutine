#include <stdbool.h>
#include "pins.h"
#include "encoder.h"

/** \fn encoder_create
 * This function initializes the encoder. It requires specifying the pin on 
 * which the encoder is connected, and the number of steps that mean a full 
 * rotation of the measured element around. By default, the first parameter 
 * is pointing to the encoder object.
 * @param *self Encoder stucture to work on it
 * @param connection Pin to which encoder is connected
 * @param full_rotate The number of ticks that represent a full turn
 */
void encoder_create(
    encoder_t *self, 
    pin_t connection, 
    encoder_ticks_t full_rotate
) {
    self->connection = connection;
    self->full_rotate = full_rotate;
    self->position = 0;

    pin_set_mode(connection, INPUT);
    
    self->last_state = pin_get_state(connection);
}

/** \fn encoder_update
 * This function checks the current status of the encoder input and updates 
 * the motor rotation status if necessary. If there are any changes, then 
 * return true.
 * @param *self Encoder structure to work on it
 * @return True if any changes corrupted, or false when not
 */
bool encoder_update(encoder_t *self) {
    pin_state_t current_state = pin_get_state(self->connection);

    if (current_state == self->last_state) return false;

    self->last_state = current_state;
    ++self->position;

    return true;
}

/** \fn encoder_ticks_left_to_trade
 * This function counts how many ticks are left until the item is fully 
 * rotated.
 * @param *self Encoder object to work on it
 * @return Counts left to fully trade
 */
encoder_ticks_t encoder_ticks_left_to_trade(encoder_t *self) {
    return (self->full_rotate - (self->position % self->full_rotate));
}

/** \fn encoder_count_trades
 * This function returns how many revolutions the motor has currently made, 
 * and resets the number of revolutions. Attention, the function does not 
 * reset the number of ticks left for a full spin. If the object has made 
 * 2.5 rotations, this function will return 2, leaving 0.5 rotations made.
 * @param *self Encoder to work on it
 * @return Count of trades
 */
encoder_ticks_t encoder_count_trades(encoder_t *self) {
    encoder_ticks_t trades = self->position / self->full_rotate;
    self->position = self->position % self->full_rotate;

    return trades;
}


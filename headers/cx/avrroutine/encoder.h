#ifndef AVRROUTINE_ENCODER_H_DEFINED
#define AVRROUTINE_ENCODER_H_DEFINED

#include <stdbool.h>
#include "pins.h"

/** \typedef encoder_ticks_t
 * That is unsigned integer type for counitng encoder ticks.
 */
#ifndef ENCODER_BIG_TICKS
typedef uint8_t encoder_ticks_t;
#else
typedef uint16_t encoder_ticks_t;
#endif

/** \struct encoder_t
 * This is struct for storing encoder object.
 */
typedef struct {
    
    /* Current object position */
    encoder_ticks_t position;
    
    /* Ticks count for full object trade */
    encoder_ticks_t full_rotate;

    /* Last state of encoder pin */
    pin_state_t last_state;

    /* Pin which encoder is connected to */
    pin_t connection; 

} encoder_t;

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
);

/** \fn encoder_update
 * This function checks the current status of the encoder input and updates 
 * the motor rotation status if necessary. If there are any changes, then 
 * return true.
 * @param *self Encoder structure to work on it
 * @return True if any changes corrupted, or false when not
 */
bool encoder_update(encoder_t *self);

/** \fn encoder_ticks_left_to_trade
 * This function counts how many ticks are left until the item is fully 
 * rotated.
 * @param *self Encoder object to work on it
 * @return Counts left to fully trade
 */
encoder_ticks_t encoder_ticks_left_to_trade(encoder_t *self);

/** \fn encoder_count_trades
 * This function returns how many revolutions the motor has currently made, 
 * and resets the number of revolutions. Attention, the function does not 
 * reset the number of ticks left for a full spin. If the object has made 
 * 2.5 rotations, this function will return 2, leaving 0.5 rotations made.
 * @param *self Encoder to work on it
 * @return Count of trades
 */
encoder_ticks_t encoder_count_trades(encoder_t *self);

#endif

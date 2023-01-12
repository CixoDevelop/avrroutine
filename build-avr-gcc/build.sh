#!/bin/bash

SOURCES=("pins.c shift_register.c timer.c serial.c")
SOURCES_DIR=../sources/

LIB=./libstdavr.a
OBJECTS_DIR=./

CC="avr-gcc"
CC_FLAGS="-Wall -Wextra -Wpedantic -Os -std=c99 -fearly-inlining \
    -fshort-enums -Wl,--gc-sections -fdata-sections -Wno-array-bounds\
    -ffunction-sections -mmcu=atmega328p"

AR="avr-ar"
AR_FLAGS="-cq"

set -x

rm $OBJECTS_DIR/*.o -f
rm $LIB -f

for SOURCE in $SOURCES; do
    $CC $CC_FLAGS -c $SOURCES_DIR/$SOURCE -o "$OBJECTS_DIR/$(basename $SOURCE .c).o"
done

$AR $AR_FLAGS $LIB $OBJECTS_DIR/*.o

rm $OBJECTS_DIR/*.o -f

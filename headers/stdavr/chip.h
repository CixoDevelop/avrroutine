#ifndef STDAVR_CHIP_H_INCLUDED
#define STDAVR_CHIP_H_INCLUDED

#include <avr/io.h>

/* This include propertly definitions for chip */

#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
#include "atmega328.h"
#endif

#if defined(__AVR_ATmega8__) || defined(__AVR_ATmega8P__)
#include "atmega8.h"
#endif

#endif

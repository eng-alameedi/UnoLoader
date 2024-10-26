//
// File: led.cpp
//
// This file contain the implementation of the led's,
// that will power-on, or blink when bootloader work.
//

#include "led.h"

#include <stdint.h>

#include "settings.h"

void led_setup() {
  _MEM_8(DDRB) = _BV(POWER_LED);   // put the builtin led on port 5, for output.
  _MEM_8(PORTB) = _BV(POWER_LED);  // set the port 5 to high voltage.

  _MEM_8(DDRD) = _BV(TX_LED) | _BV(RX_LED);   // put the builtin the tx, and rx led for output
  _MEM_8(PORTD) = _BV(TX_LED) | _BV(RX_LED);  // set the port 4, and 5 to high voltage.
}

//
// File: timer.cpp
//
// This file contain the implementation of the timer,
// and delay function using the compare time control,
// (CTC) mode.
//

#include "timer.h"

#include "settings.h"

void ctc_setup() {
  uint8_t OCR0A{249};  // [(F_CPU/(1000 * N * 2))-1] ---> (16000000/(1000 * 64 * 2))-1 = 249
  _MEM_8(TCCR0A) = 0x00;
  _MEM_8(TCCR0A) = _BV(WGM01);  // CTC mode
  _MEM_8(TCCR0B) = 0x00;
  _MEM_8(TCCR0B) = _BV(CS01) | _BV(CS00);  // set perscale to 64
  _MEM_8(TCNT0) = 0x00;
}

void delay(uint8_t ms) {
  while (ms != 0) {
    while (!(_MEM_8(TIFR0) & _BV(OCF0A)));
    _MEM_8(TIFR0) |= _BV(OCF0A);
    ms--;
  }
}

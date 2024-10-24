//
// File: watchdog.cpp
//
// This file contain the implementation code,
// for the watchdog timer settings.
//

#include "watchdog.h"

#include "settings.h"

void set_wdt() {
  _MEM_8(WDTCSR) |= _BV(WDCE) | _BV(WDE);
  _MEM_8(WDTCSR) |= _BV(WDP2) | _BV(WDP1);
}

//
// File: watchdog.h
//
// This file contain the main setup and configure,
// for the watchdog timer clock, and set the time,
// perscale to 1s to rest.
//

#ifndef _WATCHDOG_H_
#define _WATCHDOG_H_

#include <stdint.h>

#define WDTCSR (0x60)
#define WDIF (7)
#define WDIE (6)
#define WDP3 (5)
#define WDCE (4)
#define WDE (3)
#define WDP2 (2)
#define WDP1 (1)
#define WDP0 (0)

void set_wdt(void);

#endif  // _WATCHDOG_H_

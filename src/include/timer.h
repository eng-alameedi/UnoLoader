//
// File: timer.h
//
// This file contain the main definition of the delay,
// function that will count in millisecond.
//

#ifndef _TIMER_H_
#define _TIMER_H_

#include <stdint.h>

#define TCCR0A (0x44)
#define WGM01 (1)
#define WGM00 (0)

#define TCCR0B (0x45)
#define WGM02 (3)
#define CS02 (2)
#define CS01 (1)
#define CS00 (0)

#define TCNT0 (0x46)

#define TIFR0 (0x35)
#define OCF0B (2)
#define OCF0A (1)
#define TOV0 (0)

void ctc_setup();
void delay(uint8_t);

#endif  // _TIMER_H_

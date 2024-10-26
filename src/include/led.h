//
// File: led.h
//
// This file contain the main setup of the led's,
// that will power-on when bootloader work like,
// TX_LED, RX_LED, and POWER_LED.
//

#ifndef _LED_H_
#define _LED_H_

#define PINB (0x23)
#define DDRB (0x24)
#define PORTB (0x25)
#define POWER_LED (5)

#define PIND (0x29)
#define DDRD (0x2A)
#define PORTD (0x2B)
#define TX_LED (5)
#define RX_LED (4)

void led_setup(void);

#endif  // _LED_H_

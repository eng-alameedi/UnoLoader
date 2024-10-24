//
// File: main.cpp
//
// The main file for ATmega328p BootLoader
//

#include "bootloader.h"
#include "interrupt.h"
#include "settings.h"
#include "uart.h"
#include "watchdog.h"

int main() {
  if (_MEM_8(MCUSR) & _BV(EXTRF)) {
    cli();                                  // disable the external interrupt
    uart_init();                            // initialize the uart communication
    uart_send('B');                         // send a 'B' to the terminal to indicate bootloade
    set_wdt();                              // activate the watchdog timer for 1s.
    while (!(_MEM_8(UCSR0A) & _BV(RXC0)));  // infinite loop to check if there is a received code
    while (true) {
      // code for receive and write the code to memory
    }
    sei();

    while (true) {
      // infinite loop
    }
  } else {
    // code to cancel the bootloader, and go to application code.
  }
  return 0;
}

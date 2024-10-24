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
    cli();
    uart_init();
    uart_send('B');
    set_wdt();
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

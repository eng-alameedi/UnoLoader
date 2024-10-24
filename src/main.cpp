//
// File: main.cpp
//
// The main file for ATmega328p BootLoader
//

#include "bootloader.h"
#include "interrupt.h"
#include "settings.h"
#include "timer.h"
#include "uart.h"
#include "watchdog.h"

int main() {
  if (_MEM_8(MCUSR) & _BV(EXTRF)) {
    cli();                                  // disable the external interrupt
    uart_init();                            // initialize the uart communication
    uart_send('B');                         // send a 'B' to the terminal to indicate bootloade
    ctc_setup();                            // setup the timer (ctc mode), and delay(ms) function
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
    jmpapp();  // jump to application code.
  }
  return 0;
}

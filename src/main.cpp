//
// File: main.cpp
//
// The main file for ATmega328p BootLoader
//

#include "bootloader.h"
#include "settings.h"
#include "uart.h"

int main() {
  if (_MEM_8(MCUSR) & _BV(EXTRF)) {
    uart_init();
    uart_send('B');
    while (true) {
      // code for receive and write the code to memory
    }
  } else {
    // code to cancel the bootloader, and go to application code.
  }
  return 0;
}

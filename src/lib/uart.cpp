//
// File: uart.cpp
//
// This file contains the implementation of the serial,
// communication (UART) to connect with the ATmega328p,
// microchip.

#include "uart.h"

#include "settings.h"

void uart_init(void) {
  _MEM_8(UBBR0H) = (UBRR >> 8);  // set the upper byte
  _MEM_8(UBBR0L) = (UBRR);       // set the lower byte

  _MEM_8(UCSR0B) |= _BV(RXEN0) | _BV(TXEN0);    // enable the TX, and RX of the uart
  _MEM_8(UCSR0C) |= _BV(UCSZ01) | _BV(UCSZ00);  // set the serial frame to 8bit
}

void uart_send(char c) {
  while (!(UCSR0A & (_BV(UDRE0))));  // check for the UDRE0 to be set 0 (buffer ready to transmit)
  _MEM_8(UDR0) = c;
}

uint8_t uart_receive(void) {
  while (!(UCSR0A & _BV(RXC0)));  // check for the RXC0 to be set 1 (unread data)
  return _MEM_8(UDR0);
}

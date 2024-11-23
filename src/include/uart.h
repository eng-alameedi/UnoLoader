//
// File: uart.h
//
// This file contain the main register,
// and functions to initialize connection,
// between the user terminal and the MCU,
// to upload the application code.
//

#ifndef _UART_H_
#define _UART_H_

#include <stdint.h>  // used for uint8_t

#include "settings.h"  // used for the settings of all bootloader options

#define UBRR ((F_CPU / (16UL * BAUD_RATE)) - 1)  // used to calculate, and control baud rate perscale clock

#define UDR0 (0xC6)

#define UBBR0H (0xC5)

#define UBBR0L (0xC4)

#define UCSR0A (0xC0)
#define RXC0 (7)
#define TXC0 (6)
#define UDRE0 (5)
#define FE0 (4)
#define DOR0 (3)
#define UPE0 (2)
#define U2X0 (1)
#define MPCM0 (0)

#define UCSR0B (0xC1)
#define RXCIE0 (7)
#define TXCIE0 (6)
#define UDRIE0 (5)
#define RXEN0 (4)
#define TXEN0 (3)
#define UCSZ02 (2)
#define RXB80 (1)
#define TXB80 (0)

#define UCSR0C (0xC2)
#define UMSEL01 (7)
#define UMSEL00 (6)
#define UPM01 (5)
#define UPM00 (4)
#define USBS0 (3)
#define UCSZ01 (2)
#define UCSZ00 (1)
#define UCPOL0 (0)

void uart_init(void);

void uart_send(char);

uint8_t uart_receive(void);

#endif  // _UART_H_

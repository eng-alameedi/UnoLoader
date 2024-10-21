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

#include <stdint.h>

void uart_init(void);

void uart_send(uint8_t);

uint8_t uart_receive(void)

#endif  // _UART_H_

//
// File: settings.h
//
// This file contain the main settings of the,
// bootloader program, if you need to change,
// settings like baud rate, cpu frequency or,
// other do it here please.
//

#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#ifndef BAUD_RATE            // check if the baud rate not defined.
#if F_CPU >= 8000000L        // check the device type, for the ATmega328p F_CPU = 16 MIPS
#define BAUD_RATE (115200L)  // the used baud rate
#else
#define BAUBAUD_RATE (9600L)  // default baud rate.
#endif                        // BAUD_RATE

#ifndef _UBRR                                     // define the value of UART settings for ATmega328p.
#define _UBRR ((F_CPU / (16UL * BAUD_RATE)) - 1)  // define the UART settings for F_CPU 16MIPS
#endif

#define PAGESIZE (64)                // define the page size to (64) word, default to ATmega328p
#define SPM_PAGESIZE (2 * PAGESIZE)  // define the buffer size to (128) byte, default ATmega328p.
#define RAMSTART (0x100)             // define the start address of ram in ATmega328p memory address.
#define RAMEND (0x8FF)               // define the end address of ram in ATmega328p memory address.
#define FLASHEND (0x7FFF)

#define Foc0a (1000)  // for setup timer in ms
#define N (64)        // timer perscale chose (64)

#define _BV(BIT) (1 << BIT)                            // Set bit to high (1).
#define _MEM_8(reg_add) (*(volatile uint8_t*)reg_add)  // This macro used to put the memory address to work.

#endif  // _SETTINGS_H_

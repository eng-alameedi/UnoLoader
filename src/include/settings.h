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

#define Foc0a (1000)  // for setup timer in ms
#define N (64)        // timer perscale chose (64)

#define _BV(BIT) (1 << BIT)                            // Set bit to high (1).
#define _MEM_8(reg_add) (*(volatile uint8_t*)reg_add)  // This macro used to put the memory address to work.

#endif  // _SETTINGS_H_

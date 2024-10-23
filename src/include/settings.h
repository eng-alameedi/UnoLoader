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

#define BAUD (9600)  // initial baud rate

#define _BV(BIT) (1 << BIT)                            // Set bit to high (1).
#define _MEM_8(reg_add) (*(volatile uint8_t*)reg_add)  // This macro used to put the memory address to work.

#endif  // _SETTINGS_H_

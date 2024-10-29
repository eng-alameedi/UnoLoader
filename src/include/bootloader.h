//
// File: bootloader.h
//
// This file contain the main functions, and fuse
// settings for main core of bootloader for the,
// ATmega328p microcontroller
//

#ifndef _BOOTLOADER_H_
#define _BOOTLOADER_H_

#include <stdint.h>

#define PAGE_SIZE (128)  // the page size about (64 word), the result about (128 byte).

#define SPMCSR (0x57)
#define SPMIE (7)
#define RWWSB (6)
#define RWWSRE (4)
#define BLBSET (3)
#define PGWRT (2)
#define PGERS (1)
#define SELFPRGEN (0)

#define MCUSR (0x54)
#define WDRF (3)
#define BORF (2)
#define EXTRF (1)
#define PORF (0)

void page_erase(uint16_t);           // erase the page size from memory each time
void page_fill(uint16_t, uint16_t);  // fill the buffer page byte by byte
void page_write(uint16_t);           // write the page of data to memory each time.
void rww_enable();                   // enable the read while write (RWW) section.

#endif  // _BOOTLOADER_H_

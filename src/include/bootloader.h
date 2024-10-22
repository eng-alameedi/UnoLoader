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

void page_erase(uint8_t);             // erase the page size from memory each time
void page_buffer(uint8_t*, uint8_t);  // fill the buffer page byte by byte
void page_write();                    // write the page of data to memory each time.

#endif  // _BOOTLOADER_H_

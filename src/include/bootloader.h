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

#include "settings.h"

#define SPMCSR (0x57)  // define the SPM control status register, and all its bit.
#define SPMIE (7)
#define RWWSB (6)
#define RWWSRE (4)
#define BLBSET (3)
#define PGWRT (2)
#define PGERS (1)
#define SELFPRGEN (0)

#define MCUSR (0x54)  // define the microcontroller unit status register
#define WDRF (3)
#define BORF (2)
#define EXTRF (1)
#define PORF (0)

#ifndef __SPM_ENABLE              // define the SPM enable bit.
#define __SPM_ENABLE (SELFPRGEN)  // set the SPM bit to SELFPRGEN bit (0) of SPMCSR
#endif

#define spm_busy() (_MEM_8(SPMCSR) & _BV(__SPM_ENABLE))
#define spm_busy_wait() \
  do {                  \
  } while (spm_busy())

void page_erase(uint16_t);           // erase the page size from memory each time
void page_fill(uint16_t, uint16_t);  // fill the buffer page byte by byte
void page_write(uint16_t);           // write the page of data to memory each time.
void rww_enable();                   // enable the read while write (RWW) section.

#endif  // _BOOTLOADER_H_

//
// File: interrupt.h
//
// This header file, contain the main core
// components of ATmega328p BootLoader.
//

#ifndef _LOADER_CORE_H_
#define _LOADER_CORE_H_

#ifndef cli
#define cli() __asm__ __volatile__("cli" ::: "memory")
#endif  // cli()

#ifndef sei
#define sei() __asm__ __volatile__("sei" ::: "memory")
#endif  // sei()

#ifndef jmpapp
#define jmpapp() __asm__ __volatile__("jmp 0x0000")
#endif  // jmpapp()

#endif  // _LOADER_CORE_H_

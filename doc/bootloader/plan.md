## Bootloader Procedure
---

1- on reset, the bootloader check the cause of reset from ""(MCUSR ---> 0x55)"":
  - if external flag ""(EXTRF ---> bit1)"" run the bootloader code.
  - other flags run the application code ASAP.

2- start led, chose the flashing led to indicate bootloader being executed ""(the led chose is configurable)"".

3- uart initialize, configure the uart settings.

4- watchdog settings, configure the WDT ""(watchdog timer) WDTCSR (0x60)"" withing 1s set the ""(WDP2, and WDP1 to 1).

5- bootloader, the bootloader attempts to listen to send commands from uart, it store the data in a buffer page then erase the memory page by page and write a data. The WDT reset every data written to memory.

6- if no valid uart data, the WDT expire and cause chip reset.

7- while the WDT reset, is not an "external reset", the application is started as described in (1).


### Save Space Techniques (adopted from the [OptiBoot](https://github.com/Optiboot/optiboot/wiki/HowOptibootWorks))
---

In order to save space, Optiboot utilizes a couple of techniques that may be of general interest:

- The Vector table and normal startup code are omitted by using linker options ***"-nostdlib -nostartfiles"***
- This requires that main() be declared with attribute OS_main and manually placed in the .init9 section.
- and thus main() has to initialize the known-zero register (r1) and SP on chips that don't automatically set SP to end-of-ram.
- inlining of functions is carefully controlled.

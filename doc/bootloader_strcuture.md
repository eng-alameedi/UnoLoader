## Bootloader Structure

- Reset Vector: When the ***ATmega328p*** is powered on or reset, it starts executing code from the ***reset vector***. By setting the ***appropriate fuse bits***, this vector can point to the bootloader section instead of the start of the main application.

- Bootloader Code: The bootloader code typically has:

   - Initialization: Sets up the ***UART, SPI***, or other communication protocol for data transfer.
   - Flash Programming Routine: Reads data from the ***serial interface***, and writes it into the ***flash memory***.
   - Verification Routine: Ensures the program is written correctly.
   - Jump to Application: After programming, the bootloader jumps to the starting address of the application code ***(typically address 0x0000)***.

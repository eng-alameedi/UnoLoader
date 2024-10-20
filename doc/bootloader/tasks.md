## **Main Programming Tasks**

In our project, we will implement, write, and test an ***ddATmega328p bootloader in **C programming Language*****. The list of project tasks are:

- Use a ""Reset Vector"". __vector0__.
- Disable external interrupt. Write a function (cli).
- Initialize the communication protocol **(UART preferred)**. Write a function uart_tx, and uart_rx.
- Set boot section size by setting ""fuses"". Write a function boot_size().
- Disable the reading to the ***NRWW***. Write a function nrww_noread().
- Write a procedure to ***erase byte by byte*** of boot section of flash.
- Write a procedure to check the ""EEPROM read, or write"" state.
- Write a procedure to write the bootloader ""byte by byte"".
- Write a procedure to check the ""written byte"" for error, and CRC.
- Enable the reading to NRWW section.
- Enable the external interrupt. Write a function (sei).
- Jump to the application section of flash.

The header files will be create for each section of bootloader, and update every time as needed. In this bootloader optimization, efficiency, and size.

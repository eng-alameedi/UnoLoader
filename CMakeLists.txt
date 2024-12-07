cmake_minimum_required(VERSION 3.20)

project(UnoLoader
        VERSION 1.0.0
        LANGUAGES C CXX ASM
)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)

set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_ASM_COMPILER avr-as)

set(MCU atmega328p)
set(F_CPU 16000000UL)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(file_name BootLoader)
file(GLOB SOURCES
     src/main.cpp
     src/lib/*.cpp
)

add_executable(${file_name} ${SOURCES})

target_include_directories(${file_name} PRIVATE ${PROJECT_SOURCE_DIR}/src/include)

set_target_properties(${file_name} PROPERTIES
     COMPILE_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU}"
     LINK_FLAGS "-mmcu=${MCU}"
)

add_custom_command(TARGET ${file_name}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/boot
)

add_custom_command(TARGET ${file_name}
  POST_BUILD
  COMMAND avr-objcopy -O ihex -R .eeprom ${file_name} ${CMAKE_BINARY_DIR}/boot/${file_name}.hex
  COMMENT "Generation Bootloader HEX file for Arduino"
)

add_custom_target(upload
  COMMAND avrdude -c arduino -p m328p -P /dev/ttyUSB0 -U flash:w:${CMAKE_BINARY_DIR}/boot/${file_name}.hex:i
  DEPENDS ${file_name}.hex
  COMMENT "Uploading Bootloader HEX file to Arduino"
)

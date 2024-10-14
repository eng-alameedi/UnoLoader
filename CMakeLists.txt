cmake_minimum_required(VERSION 3.20)

project(UnoLoader
        VERSION 1.0.0
        LANGUAGES C CXX ASM
)

set(file_name BootLoader)

set(MCU atmega328p)
set(F_CPU 16000000UL)

file(SOURCES GLOB
     src/main.cpp
     src/lib/*.cpp
)

add_executable(${file_name} ${SOURCES})

set_target_properties(${file_name} PROPERTIES
     COMPILE_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU}"
     LINK_FLAGS "-mmcu=${MCU}"
)

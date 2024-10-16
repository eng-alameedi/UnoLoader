cmake_minimum_required(VERSION 3.20)

project(UnoLoader
        VERSION 1.0.0
        LANGUAGES C CXX ASM
)

set(file_name BootLoader)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)

set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)

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

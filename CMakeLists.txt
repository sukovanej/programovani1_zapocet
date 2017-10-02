cmake_minimum_required(VERSION 3.8)
project(programovani1_zapocet)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c src/test.h src/test.c src/cetnost.h src/cetnost.c src/types.h src/mincovka.c src/mincovka.h)
add_executable(programovani1_zapocet ${SOURCE_FILES})
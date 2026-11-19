cmake_minimum_required(VERSION 3.16)
project(c_data_structures C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Every .c file is a standalone program with its own main(),
# so build each one as a separate executable named after the file.
file(GLOB_RECURSE PROGRAMS CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/0*/*.c")

foreach(src ${PROGRAMS})
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src})
endforeach()

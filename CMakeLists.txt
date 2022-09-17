cmake_minimum_required (VERSION 3.16)

project(
    aarch64_interpreter
    VERSION 0.0.1
    DESCRIPTION "AArch64 Interpreter"
    LANGUAGES C)

# make settings for clangd/cppcheck
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# C language settings
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic -g")

# set build type: {Debug, RelWithDebInfo, Release}
set(CMAKE_BUILD_TYPE Debug)

# library with core functions
set(LIB_COMMON aarch64_interpreter_lib)
add_library(${LIB_COMMON} OBJECT "")
target_include_directories(${LIB_COMMON} PRIVATE src)

# main executable
set(EXECUTABLE_NAME aarch64_interpreter)
add_executable(${EXECUTABLE_NAME} src/main.c)
target_include_directories(${EXECUTABLE_NAME} PRIVATE src)
target_link_libraries(${EXECUTABLE_NAME} ${LIB_COMMON})

# source directories
add_subdirectory(src)
cmake_minimum_required(VERSION 3.10)
project(V_Memory)

# Set C standard
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED True)

# Include directory
include_directories(include)

# Source files
set(SOURCES
    src/v_memory.c
    test.c
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

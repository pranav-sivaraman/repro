cmake_minimum_required(VERSION 3.18)

project(
    Reproducer
    VERSION 1.0
    LANGUAGES CXX
)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(SOURCE main.cpp)

add_executable(repro ${SOURCE})

message(STATUS "CXX Compiler: ${CMAKE_CXX_COMPILER_ID} (${CMAKE_CXX_COMPILER})")

separate_arguments(OFFLOAD_FLAGS)
target_compile_options(repro PUBLIC "$<$<CONFIG:RELEASE>:${OFFLOAD_FLAGS}>")
target_link_options(repro PUBLIC "$<$<CONFIG:RELEASE>:${OFFLOAD_FLAGS}>")

install(TARGETS repro DESTINATION bin)

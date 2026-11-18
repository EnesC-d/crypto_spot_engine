cmake_minimum_required(VERSION 3.24)

project(crypto_spot_engine LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the build type" FORCE)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(spot_engine INTERFACE)

target_include_directories(
    spot_engine
    INTERFACE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"   
)
target_compile_features(spot_engine INTERFACE cxx_std_20)

target_compile_options(
    spot_engine
    INTERFACE
        -Wall 
        -Wextra 
        -Wpedantic
        -fno-exceptions
    )

add_executable(
    engine
    src/engine.cpp
)

target_link_libraries(
    engine
    PRIVATE
        spot_engine
)

set_target_properties(
    engine
    PROPERTIES
        OUTPUT_NAME "engine"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"   
)
cmake_minimum_required(VERSION 3.5)

enable_testing()
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(target "ODataServer")
project(${target} LANGUAGES CXX)

add_definitions(-DODATASERVER_LIBRARY)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC
    "*.cpp"
)
file(GLOB HEADER
    "*.h"
    "*.hpp"
)
add_library(${target} SHARED ${SRC})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(Qt5Core REQUIRED)
qt5_use_modules(${target} Core)
target_include_directories(${target} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)    
add_subdirectory(tests)
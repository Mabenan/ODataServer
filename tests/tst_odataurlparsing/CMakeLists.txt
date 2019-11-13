cmake_minimum_required(VERSION 3.5)

set(target "ODataUrlParsingTest")
enable_testing()
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
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
  add_executable(${target} ${SRC} ${HEADER})
find_package(Qt5Core REQUIRED)
qt5_use_modules(${target} Core Test)

add_test(${target} ${CMAKE_BINARY_DIR}/bin/${target})
    set_property(TEST ${target} PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${CMAKE_BINARY_DIR}/bin:${CMAKE_BINARY_DIR}/lib")
target_link_libraries(${target} ODataServer)
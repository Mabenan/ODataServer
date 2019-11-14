cmake_minimum_required(VERSION 3.5)

set(target "ODataEntityPluginTest")
add_definitions(-DODATAENTITY_PLUGIN_TEST)
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

set_target_properties(${target}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${target}"
)
add_unit_test(${target})
add_custom_command(TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ODataServer> ${CMAKE_BINARY_DIR}/bin/${target}
)
    if(WIN32)               
    STRING(REPLACE "\\;" ";" PATH_STRING "$ENV{PATH}${CMAKE_BINARY_DIR}/bin;${CMAKE_BINARY_DIR}/lib")
    STRING(REPLACE ";" "\\;" PATH_STRING "${PATH_STRING}")
    set_property(TEST ${target} PROPERTY ENVIRONMENT "PATH=${PATH_STRING}" )
     else()
    set_property(TEST ${target} PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${CMAKE_BINARY_DIR}/bin:${CMAKE_BINARY_DIR}/lib" )
     endif()
target_link_libraries(${target} ODataServer)
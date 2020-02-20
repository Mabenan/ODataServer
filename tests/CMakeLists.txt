cmake_minimum_required(VERSION 3.5)

enable_testing()
configure_file(gtest/CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()
# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)
include(GoogleTest)
mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)
add_subdirectory("tst_odataentityplugin_plugin_lib")
set(target "ODataServerTest")
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
find_package(Qt5Xml REQUIRED)
qt5_use_modules(${target} Core Xml)

set_target_properties(${target}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)    
gtest_discover_tests(${target})    
add_test(${target} COMMAND ${CMAKE_BINARY_DIR}/bin/${target})
add_custom_command(TARGET ${target} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ODataServer> ${CMAKE_BINARY_DIR}/bin )
    if(WIN32)
    STRING(REPLACE "\\;" ";" PATH_STRING "$ENV{PATH}${CMAKE_BINARY_DIR}/bin;${CMAKE_BINARY_DIR}/lib")
    STRING(REPLACE ";" "\\;" PATH_STRING "${PATH_STRING}")
#    set_property(TEST ${target} PROPERTY ENVIRONMENT "PATH=${PATH_STRING}" )
     else()
#    set_property(TEST ${target} PROPERTY ENVIRONMENT "LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${CMAKE_BINARY_DIR}/bin:${CMAKE_BINARY_DIR}/lib" )
     endif()
target_link_libraries(${target} ODataServer ODataServerEntityPlugin_TEST_lib gtest_main)
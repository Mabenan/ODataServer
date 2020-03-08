include(GoogleTest)
mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)
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
target_link_libraries(${target} ODataServer gtest_main)
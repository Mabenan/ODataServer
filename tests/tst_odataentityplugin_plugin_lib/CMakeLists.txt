set(target "ODataServerEntityPlugin_TEST_lib")

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
find_package(Qt5Xml REQUIRED)
qt5_use_modules(${target} Core Xml)
target_include_directories(${target} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
)    
qt5_use_modules(${target} Core Test)

set_target_properties(${target}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
export(TARGETS ${target} FILE ${target}-exports.cmake EXPORT_LINK_INTERFACE_LIBRARIES)
target_link_libraries(${target} ODataServer)
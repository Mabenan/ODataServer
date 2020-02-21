cmake_minimum_required(VERSION 3.5)
if(NOT CMAKE_PROJECT_NAME)
project("ODataServer" LANGUAGES CXX)
include(GoogleTest.cmake)
endif()


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXEC_FOLDER "bin")

if(WIN32)
set(LIB_FOLDER "bin")
else()
set(LIB_FOLDER "lib")
endif()
set(INCLUDE_FOLDER "include")
set(PLUGIN_FOLDER "${EXEC_FOLDER}/plugins")

add_subdirectory(src)
add_subdirectory(tests)
if(${PACKAGE})
include("Package.cmake")
endif()
 
install(
  EXPORT ODataServer
  DESTINATION ${LIB_FOLDER}
  )

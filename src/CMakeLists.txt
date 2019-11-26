set(target "ODataServer")

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
MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${curdir}/${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()
SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})
FOREACH(subdir ${SUBDIRS})
  ADD_SUBDIRECTORY(${subdir})
ENDFOREACH()
FOREACH(srcfile ${SRC})
message(${srcfile})
endforeach()
add_library(${target} SHARED ${SRC})
SET(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} ${SUBDIRS})
include_directories(${INCLUDE_DIRS} )

find_package(Qt5Core REQUIRED)
find_package(Qt5Xml REQUIRED)
qt5_use_modules(${target} Core Xml)
target_include_directories(${target} PUBLIC 
    ${INCLUDE_DIRS}
)    
set_target_properties(${target} PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${INCLUDE_DIRS}
    )
export(TARGETS ${target} FILE ${target}-exports.cmake EXPORT_LINK_INTERFACE_LIBRARIES)
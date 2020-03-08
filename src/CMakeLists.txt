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
FOREACH(subdir ${SUBDIRS})
LIST( APPEND include_sub_dir_list $<BUILD_INTERFACE:${subdir}>)
endforeach()
add_library(${target} SHARED ${SRC})
SET(INCLUDE_DIRS $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> ${include_sub_dir_list})
include_directories(${INCLUDE_DIRS} )

find_package(Qt5Core REQUIRED)
find_package(Qt5Xml REQUIRED)
qt5_use_modules(${target} Core Xml)
target_include_directories(${target} PUBLIC 
    ${INCLUDE_DIRS}
)    
install(FILES ${HEADER} DESTINATION "${INCLUDE_FOLDER}")
install(TARGETS ODataServer EXPORT ODataServer 
LIBRARY DESTINATION "${LIB_FOLDER}"
    ARCHIVE DESTINATION "${LIB_FOLDER}"
    RUNTIME DESTINATION "${EXEC_FOLDER}"
    INCLUDES DESTINATION "${INCLUDE_FOLDER}")
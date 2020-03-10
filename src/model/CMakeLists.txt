
add_definitions(-DODATASERVER_LIBRARY)
add_definitions (-DCMAKE_CXX_COMPILER_ARG1=-std=c++20)
file(GLOB SRCl
    "*.cpp"
)
file(GLOB HEADERl
    "*.h"
    "*.hpp"
)
set(SRC ${SRC} ${SRCl} PARENT_SCOPE)
set(HEADER ${HEADER} ${HEADERl} PARENT_SCOPE)
cmake_minimum_required(VERSION 3.5)

enable_testing()

project("ODataServer" LANGUAGES CXX)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

function(add_unit_test target)
get_property(UNIT_TEST_TARGETS_L GLOBAL PROPERTY UNIT_TEST_TARGETS)
    set_property(GLOBAL PROPERTY UNIT_TEST_TARGETS ${UNIT_TEST_TARGETS_L} ${target})
add_test(NAME ${target} COMMAND ${target} -v2 WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${target})
endfunction()
add_subdirectory(src)
add_subdirectory(tests)
get_property(UNIT_TEST_TARGETS_L GLOBAL PROPERTY UNIT_TEST_TARGETS)
message(${UNIT_TEST_TARGETS_L})
option(RUN_TESTS "Build Desktop App" ON)

if(RUN_TESTS)
add_custom_target( all_tests ALL DEPENDS ${UNIT_TEST_TARGETS_L} )
add_custom_command(TARGET "all_tests"
                   COMMENT "Run tests"
                   POST_BUILD COMMAND ctest --verbose
                   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
endif()
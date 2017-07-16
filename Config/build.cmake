# Create test coverage target (gcov)
if (CMAKE_BUILD_TYPE STREQUAL "Coverage")
    message("-- Activate Coverage for ${PROJECT_NAME}")
	set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
	set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
    set(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

endif()

# Global includes. Used by all targets
# Note:
#   * header location in project: Foo/Source/foo/Bar.hpp
#   * header can be included by C++ code `#include <foo/Bar.hpp>`
#   * header location in project: ${CMAKE_CURRENT_BINARY_DIR}/bar_export.hpp
#   * header can be included by: `#include <bar_export.hpp>`
target_include_directories(
    ${PROJECT_NAME} 
    
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Sources>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"

)

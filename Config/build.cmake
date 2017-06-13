# Find Curl
find_package(CURL REQUIRED)

# Include sub projects
find_dependencies(cxx-log)
find_dependencies(swarm-commons)
find_dependencies(swarm-mapping)
find_dependencies(swarm-http-api)
find_dependencies(swarm-http-server)
find_dependencies(swarm-http-fcgi)

# Create targets
add_executable(swarm-http-sample
    Sources/swarm/http/main.cxx
    Sources/swarm/http/process/RequestInfoProcess.cxx Sources/swarm/http/process/RequestInfoProcess.hxx
)

# Properties of targets

# Add definitions for targets
# Values:
#   * Debug: -DSWARM_HTTP_SAMPLE_DEBUG=1
#   * Release: -DSWARM_HTTP_SAMPLE_DEBUG=0
#   * other: -DSWARM_HTTP_SAMPLE_DEBUG=0
target_compile_definitions(swarm-http-sample  PUBLIC "SWARM_HTTP_SAMPLE_DEBUG=$<CONFIG:Debug>")

# Global includes. Used by all targets
target_include_directories(
    swarm-http-sample
    
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Sources>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
        
    PRIVATE
        ${cxx-log_INCLUDE_DIR}
        ${swarm-commons_INCLUDE_DIR}
        ${swarm-mapping_INCLUDE_DIR}
        ${swarm-http-api_INCLUDE_DIR}
        ${swarm-http-server_INCLUDE_DIR}
        ${swarm-http-fcgi_INCLUDE_DIR}
)

target_link_libraries(
    swarm-http-sample

    cxx-log
    swarm-commons
    swarm-mapping
    swarm-http-api
    swarm-http-server
    swarm-http-fcgi
)

# Targets:
#   * <prefix>/lib/${target}.a
#   * header location after install: <prefix>/include/*.hxx
#   * headers can be included by C++ code `#include <project/*.hxx>`
install(
    TARGETS swarm-http-sample
    EXPORT "${targets_export_name}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
)

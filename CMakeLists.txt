# Set minimum version of CMake.
cmake_minimum_required(VERSION 3.8)

# Set variables:
#   * PROJECT_NAME
#   * PROJECT_VERSION
project(swarm-http-sample VERSION 0.1.0)

# Include config
include(Config/config.cmake)

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

# Local includes
target_include_directories(
    swarm-http-sample
        
    PRIVATE
        ${cxx-log_INCLUDE_DIR}
        ${swarm-commons_INCLUDE_DIR}
        ${swarm-mapping_INCLUDE_DIR}
        ${swarm-http-api_INCLUDE_DIR}
        ${swarm-http-server_INCLUDE_DIR}
        ${swarm-http-fcgi_INCLUDE_DIR}
)

# Target link
target_link_libraries(
    swarm-http-sample

    cxx-log
    swarm-commons
    swarm-mapping
    swarm-http-api
    swarm-http-server
    swarm-http-fcgi
)

# Include build
include(Config/build.cmake)

# Include test
add_subdirectory(Tests)

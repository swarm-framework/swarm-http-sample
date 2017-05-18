
# Enable ExternalProject CMake module
include(ExternalProject)

# swarm-http-fcgi version
set(swarm-http-fcgi-VERSION master)

# Download and install murmuration-core
ExternalProject_Add(
    swarm-http-fcgi
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/Dependencies/volatile
    GIT_REPOSITORY git@github.com:swarm-framework/swarm-http-fcgi.git
    GIT_TAG "${swarm-http-fcgi-VERSION}"
    INSTALL_COMMAND ""
)

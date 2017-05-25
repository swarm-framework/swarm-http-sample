
# Add sources files
set (${PROJECT_NAME}_SOURCES
    swarm/http/main.cxx
)


# Add sample serveur
add_executable(${PROJECT_NAME}
    ${${PROJECT_NAME}_SOURCES}
)

# Link library
target_link_libraries(${PROJECT_NAME}
    swarm-http-fcgi
    ${LibFCGI}
    ${LibFCGI++}
)

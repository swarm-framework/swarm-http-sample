
# Add sources files
set (${PROJECT_NAME}_SOURCES
    main.cxx
)

# Create create executable
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})

# Install exec in bin directory
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

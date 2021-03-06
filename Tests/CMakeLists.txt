# Set catch version
set(CATCH_VERSION v1.9.3)

# Set download file
set(CATCH_FILE_PATH ${PROJECT_SOURCE_DIR}/Dependencies/volatile/${CATCH_VERSION}/catch/catch.hxx)

# Test if file does not exist
if (NOT "${CATCH_FILE_PATH}")
    # Download Catch Unit test
    file(DOWNLOAD "https://github.com/philsquared/Catch/releases/download/${CATCH_VERSION}/catch.hpp" "${CATCH_FILE_PATH}")
endif()

# Create create executable
add_executable(${PROJECT_NAME}Tests 
    main.cxx
    
    sample/SampleTest.cxx
)

target_include_directories(
    ${PROJECT_NAME}Tests  
    
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Sources>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
        
    PRIVATE
        ../Sources
        ${cxx-log_INCLUDE_DIR}
        ${swarm-commons_INCLUDE_DIR}
        ${PROJECT_SOURCE_DIR}/Dependencies/volatile/${CATCH_VERSION} # catch directory
)


# Register test
add_test(${PROJECT_NAME}Tests ${PROJECT_NAME}Tests)

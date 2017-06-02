if(EXISTS ${PROJECT_SOURCE_DIR}/Dependencies/cxx-log/CMakeLists.txt)

    if(NOT TARGET cxx-log)
    # Include cxx-log
        add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/cxx-log)

        # Include sources
        include_directories(${PROJECT_SOURCE_DIR}/Dependencies/cxx-log/Sources)
    endif()

endif()

if(EXISTS ${PROJECT_SOURCE_DIR}/Dependencies/swarm-commons/CMakeLists.txt)

    if(NOT TARGET cxx-commons)
        # Include swarm-commons
        add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/swarm-commons)

        # Include sources
        include_directories(${PROJECT_SOURCE_DIR}/Dependencies/swarm-commons/Sources)
    endif()

endif()


if(EXISTS ${PROJECT_SOURCE_DIR}/Dependencies/swarm-mapping/CMakeLists.txt)

    if(NOT TARGET cxx-mapping)
        # Include swarm-mapping
        add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/swarm-mapping)

        # Include sources
        include_directories(${PROJECT_SOURCE_DIR}/Dependencies/swarm-mapping/Sources)
    endif()

endif()

if(EXISTS ${PROJECT_SOURCE_DIR}/Dependencies/swarm-http-api/CMakeLists.txt)

    if(NOT TARGET cxx-http-api)
        # Include swarm-http-api
        add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/swarm-http-api)

        # Include sources
        include_directories(${PROJECT_SOURCE_DIR}/Dependencies/swarm-http-api/Sources)
    endif()

endif()

if(EXISTS ${PROJECT_SOURCE_DIR}/Dependencies/swarm-http-server/CMakeLists.txt)

    if(NOT TARGET cxx-http-server)
        # Include swarm-http-server
        add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/swarm-http-server)

        # Include sources
        include_directories(${PROJECT_SOURCE_DIR}/Dependencies/swarm-http-server/Sources)
    endif()

endif()

if(EXISTS ${PROJECT_SOURCE_DIR}/Dependencies/swarm-http-fcgi/CMakeLists.txt)

    if(NOT TARGET cxx-http-fcgi)
        # Include swarm-http-fcgi
        add_subdirectory(${PROJECT_SOURCE_DIR}/Dependencies/swarm-http-fcgi)

        # Include sources
        include_directories(${PROJECT_SOURCE_DIR}/Dependencies/swarm-http-fcgi/Sources)
    endif()

endif()


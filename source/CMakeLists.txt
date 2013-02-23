# Minimum version required
cmake_minimum_required(VERSION 2.6)

# Project name
project(mfe)

# Add Header files here
set ( HEADERS
    events/ievent.h
    events/event.h
    core/enginecore.h
    core/ienginecore.h
    mfe.h
)

# Add source files here
set ( SOURCE
    events/event.cpp
    core/enginecore.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCE})

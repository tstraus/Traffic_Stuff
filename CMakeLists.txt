cmake_minimum_required(VERSION 3.0)
project(Traffic_Stuff)

set(CMAKE_CXX_STANDARD 11)

find_package(Threads)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/data/Vehicles.json ${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug/Vehicles.json COPYONLY)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/header
)

set(SOURCE
    source/main.cpp
    source/Vehicle.cpp
)

set(HEADER
    header/Vehicle.h
)
add_executable(${PROJECT_NAME}
    ${SOURCE}
    ${HEADER}
)

target_link_libraries(${PROJECT_NAME}
        ${CMAKE_THREAD_LIBS_INIT}
)
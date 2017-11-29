cmake_minimum_required(VERSION 3.6)
project(Traffic_Stuff)

find_package(Threads)

set(CMAKE_CXX_STANDARD 11)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Vehicles.json ${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug/Vehicles.json COPYONLY)

set(SOURCE_FILES main.cpp Vehicle.cpp Vehicle.h json.hpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
        ${CMAKE_THREAD_LIBS_INIT}
)
cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(worker)

add_subdirectory(libzmq)
add_subdirectory(cppzmq)

find_package(cppzmq)

add_executable(worker src/main.cpp)
set_target_properties(worker PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set_target_properties(worker PROPERTIES LINK_FLAGS "-static")
target_link_libraries(worker cppzmq-static)

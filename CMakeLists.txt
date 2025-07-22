cmake_minimum_required(VERSION 3.10)

project(NetworkScanner)

include_directories(Utils/include)

set(SOURCES
main.cpp
Utils/src/network_utils.cpp
)

add_executable(scanner ${SOURCES})

find_package(Threads REQUIRED)
target_link_libraries(scanner PRIVATE Threads::Threads)
cmake_minimum_required(VERSION 3.26)
project(p)

find_package(charls 2.2.0 CONFIG REQUIRED)

add_executable(foo foo.cxx)
target_link_libraries(foo PRIVATE charls)
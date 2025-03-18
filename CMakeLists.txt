cmake_minimum_required(VERSION 3.5)

project(lest)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

add_subdirectory(src)
add_subdirectory(sample)
# add_subdirectory(tests)
add_subdirectory(playground)
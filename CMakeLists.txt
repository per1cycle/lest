cmake_minimum_required(VERSION 3.5)

project(lest)
set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)

# add generate option 
option(LEST_GENERATE_REPORT "Generate report" ON)
if (LEST_GENERATE_REPORT)
    find_package(LibXml2 REQUIRED)
    include_directories(${LIBXML2_INCLUDE_DIRS})
    link_directories(${LIBXML2_LIBRARY_DIRS})
    add_definitions(-DLEST_GENERATE_REPORT)

endif()

add_subdirectory(src)
add_subdirectory(sample)
# add_subdirectory(tests)
add_subdirectory(playground)
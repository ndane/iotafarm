cmake_minimum_required(VERSION 2.6)
project(farm)

set(GLOBAL_OUTPUT_PATH ${PROJECT_BINARY_DIR})
set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR})

include(CMakeLists-External.txt)

link_directories(${GLOBAL_OUTPUT_PATH})
include_directories(${ccurl_INCLUDE_DIRS})

file(GLOB SOURCES "src/*.c" "src/crypto/*.c")

add_executable(farm ${SOURCES})

target_link_libraries(farm ${ccurl_LIBRARIES})
add_dependencies(farm ccurl)

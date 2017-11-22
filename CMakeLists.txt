cmake_minimum_required (VERSION 2.6)
project (farm)

include_directories("${PROJECT_SOURCE_DIR}/libs/ccurl")
include_directories("${PROJECT_SOURCE_DIR}/libs/opencl/include")

file(GLOB SOURCES "src/*.c" "src/crypto/*.c")

add_executable(farm ${SOURCES})

cmake_minimum_required(VERSION 3.22)
project(windowsapp_singleton)

set(CMAKE_CXX_STANDARD 17)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)

add_library(${PROJECT_NAME} SHARED ${SRC})

add_subdirectory(tests)

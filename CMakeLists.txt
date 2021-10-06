cmake_minimum_required(VERSION 3.15)
project(folderJunker VERSION 1.0.0)


message("Build system for folderJunker")
add_subdirectory(libfj)
include_directories(libfj/include)
add_executable(folderJunker folderJunker.cpp)

target_link_libraries(folderJunker libfj)
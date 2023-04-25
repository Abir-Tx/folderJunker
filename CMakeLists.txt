# CMAKE BUILD SYSTEM FOR FOLDERJUNKER PROJECT BY ABIR-TX

cmake_minimum_required(VERSION 3.15)
project(folderJunker VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)



message("Build system for folderJunker")
add_subdirectory(libfj)
include_directories(libfj/include)
add_executable(folderJunker folderJunker.cpp)

target_link_libraries(folderJunker libfj -static-libgcc -static-libstdc++ -static -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic)
cmake_minimum_required(VERSION 3.2)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(include)
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

add_executable(cpp src/main.cpp src/writer.cpp include/writer.h include/header.h src/header.cpp src/chunk.cpp include/chunk.h src/Buffer.cpp include/Buffer.h src/common.cpp include/common.h)
cmake_minimum_required(VERSION 3.17)
project(Containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(Containers Src/list_test.cpp Src/vector_test.cpp Src/map_test.cpp Src/stack_test.cpp Src/queue_test.cpp Src/main.cpp)
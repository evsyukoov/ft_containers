cmake_minimum_required(VERSION 3.17)
project(Containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(Containers stack.hpp  list.hpp vector.hpp ListIterator.hpp VectorIterator.hpp queue.hpp  map.hpp list_test.cpp MapIterator.hpp Tree.hpp)
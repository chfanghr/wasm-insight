cmake_minimum_required(VERSION 3.10)
project(data C)

set(CMAKE_C_STANDARD 11)

add_library(data data.c type.h container.h)
add_library(array array/array.c array/array.h)
add_library(deque deque/deque.c deque/deque.h)
add_library(list list/list.c list/list.h)
add_library(set set/set.c set/set.h)
add_library(stack stack/stack.h stack/stack.c)
add_library(vector vector/vector.c vector/vector.h)

target_link_libraries(stack deque)
target_link_libraries(data array deque list set stack vector)
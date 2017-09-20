cmake_minimum_required(VERSION 3.8)
project(Algorithm_Interview2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp "283. Move Zeroes.h" "27. Remove Element.h" "26. Remove Duplicates from Sorted Array.h" "80. Remove Duplicates from Sorted Array II.h" "75. Sort Colors.h")
add_executable(Algorithm_Interview2 ${SOURCE_FILES})
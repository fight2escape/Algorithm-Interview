cmake_minimum_required(VERSION 3.8)
project(Algorithm_Interview2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp "数组相关/283. Move Zeroes.h" "数组相关/27. Remove Element.h" "数组相关/26. Remove Duplicates from Sorted Array.h" "数组相关/80. Remove Duplicates from Sorted Array II.h" "数组相关/75. Sort Colors.h" "数组相关/88. Merge Sorted Array.h" "数组相关/215. Kth Largest Element in an Array.h" "数组相关/167. Two Sum II - Input array is sorted.h" "数组相关/125. Valid Palindrome.h" "数组相关/344. Reverse String.h" "数组相关/345. Reverse Vowels of a String345..h" "数组相关/11. Container With Most Water.h" "数组相关/209. Minimum Size Subarray Sum.h" "数组相关/3. Longest Substring Without Repeating Characters.h")
add_executable(Algorithm_Interview2 ${SOURCE_FILES})
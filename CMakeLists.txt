cmake_minimum_required(VERSION 3.8)
project(Algorithm_Interview2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp "283. Move Zeroes.h" "27. Remove Element.h" "26. Remove Duplicates from Sorted Array.h" "80. Remove Duplicates from Sorted Array II.h" "75. Sort Colors.h" "88. Merge Sorted Array.h" "215. Kth Largest Element in an Array.h" "167. Two Sum II - Input array is sorted.h" "125. Valid Palindrome.h" "344. Reverse String.h" "345. Reverse Vowels of a String345..h" "11. Container With Most Water.h" "209. Minimum Size Subarray Sum.h" "3. Longest Substring Without Repeating Characters.h")
add_executable(Algorithm_Interview2 ${SOURCE_FILES})
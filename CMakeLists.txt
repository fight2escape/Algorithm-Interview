cmake_minimum_required(VERSION 3.8)
project(Algorithm_Interview2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp "Array/283. Move Zeroes.h" "Array/27. Remove Element.h" "Array/26. Remove Duplicates from Sorted Array.h" "Array/80. Remove Duplicates from Sorted Array II.h" "Array/75. Sort Colors.h" "Array/88. Merge Sorted Array.h" "Array/215. Kth Largest Element in an Array.h" "Array/167. Two Sum II - Input array is sorted.h" "Array/125. Valid Palindrome.h" "Array/344. Reverse String.h" "Array/345. Reverse Vowels of a String345..h" "Array/11. Container With Most Water.h" "Array/209. Minimum Size Subarray Sum.h" "Array/3. Longest Substring Without Repeating Characters.h" "Search(Set-Map)/349. Intersection of Two Arrays.h" "Search(Set-Map)/350. Intersection of Two Arrays II.h" "Search(Set-Map)/1. Two Sum.h" "Search(Set-Map)/454. 4Sum II.h" "Search(Set-Map)/447. Number of Boomerangs.h" "Search(Set-Map)/219. Contains Duplicate II.h")
add_executable(Algorithm_Interview2 ${SOURCE_FILES})
# Searching-Lab
Week 2 CISC 187


##Steps it would take to perform a linear search for the number 8 in the ordered array, [2, 4, 6, 8, 10, 12, 13]? 

A linear search compares one element in the list at a time to the inputted search. In this case it would check arr[0], arr[1], arr[2], and finally arr[3], where 8 resides. This results in 4 total steps, with the 4th being the actual result. O(4).

##How many steps would binary search take for the previous example? 

A binary search would start at the middle element and compare it to the desired search. In this case our middle element is 8, so we would arrive at it right away. This would take one step total. (I believe, unit test later)

##What is the maximum number of steps it would take to perform a binary search on an array of size 100,000?

Using the given formula in our book and plugging in 100,000 as our N I got 16.6, but we have to round up to the nearest integer, which would give us 17 steps max.

## Write a C++ program that implements both linear search and binary search algorithms using an array of 100,000 elements. The program should record and report the number of steps (comparisons) performed during each search operation. In addition, analyze and justify the observed behavior by providing a theoretical explanation using Big-O notation, demonstrating why linear search exhibits O(N) complexity and binary search exhibits O(logN) complexity.
# Searching-Lab
Week 2 CISC 187


## Task 1: Steps it would take to perform a linear search for the number 8 in the ordered array, [2, 4, 6, 8, 10, 12, 13]? 

A linear search compares one element in the list at a time to the inputted search. In this case it would check arr[0], arr[1], arr[2], and finally arr[3], where 8 resides. This results in 4 total steps, with the 4th being the actual result.

## Task 2: How many steps would binary search take for the previous example? 

A binary search would start at the middle element and compare it to the desired search. In this case our middle element is 8, so we would arrive at it right away. This would take one step total.

## Task 3: What is the maximum number of steps it would take to perform a binary search on an array of size 100,000?

Using the given formula in our book and plugging in 100,000 as our N I got 16.6, but we have to round up to the nearest integer, which would give us 17 steps max.

## Task 4: Write a C++ program that implements both linear search and binary search algorithms using an array of 100,000 elements.

### Linear search Algorithm
O(N) Because we consider each element in comparison to our desired value, which means the worst-case is ending at the last element, or N, the entire length of the array.
```C++
int linear_Search(int arr[], int n, int search, double& comparisons){
    comparisons = 0;
    for (int i = 0; i < n; i++){
        comparisons++;
        if(arr[i] == search) return i;
    }
    return -1;
}
```
### Binary search Algorithm
O(logN). Worst-case we have to split our array in half as many time as we can, leading to an answer of logbase2(N). 
```C++
int binary_Search(int arr[], int n, int search, int& comparisons){
    comparisons = 0;
    int low = 0, high = n-1; //setting initial indexes for search

    while (low <= high){
        int mid = low + (high - low) / 2; //consistent middle
        comparisons++;
        if (arr[mid] == search) return mid;

        //comparisons++; 
        
        if(search < arr[mid])
            high = mid -1;
        else 
            low = mid +1;
    }
    return -1;
}
```

## Task 5 Randomized Search Algorithm

### PseudoCode (Part 1 Task 5)
(First time writing pseudocode, please let me know if anything is off.)

:= is assignment

... is through (ie) index[0] through index[n]

```
function rand_Search(array, key) is 
    n := size(array)
    visited[0 ... n-1] := false
    totalComparisons := 0

    while n > 0 do
        i := random integer
        if visited[i] is false then
            visited[i] := true
            n := n - 1
            totalComparisons := totalComparison + 1

            if array[i] is equal to key then:
                return i

    return unsuccessful
```
### Code (Part 2 Task 5)
```C++
int rand_Search(const vector<int>& vec, int key, double& comparisons){
    int n = vec.size();   
    vector<bool> visited(n, false);

    int remaining = n;
    comparisons = 0;    

    mt19937 gen(random_device{}());
    uniform_int_distribution<int> rand(0, n - 1);

    while (remaining > 0) {
        int i = rand(gen);

        if(!visited[i]){
            visited[i] = true;
            remaining--;
            comparisons++;
            if(vec[i] == key) return i;
        }
    }
    return -1;
}
```

### Logic Discussion (part 3 task 5)

* Time Complexity Linear Search (Does not require ordering on datasets):
   * Best Case: O(1)
   * Worst Case: O(N)
   * Does not require an ordered array. Good for smaller datasets, minimal overhead needed.

* Time Complexity Binary Search (Requires Ordering/Sorting):
   * Best Case: O(1)
   * Worst Case: O(log N)  or (log_10 N) / (log_10 2)
   * Best for larger datasets.

* Time Complexity Random Search (Does not require ordering on datasets):
   * Best Case: O(1)
   * Worst Case: O(N)
   * Good for cases where you need randomization, such as a lottery draw, a random dataset. Still O(N). Not as reliable, but if elements are weighted evenly it can find uses. Very niche.

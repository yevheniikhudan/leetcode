# Kth Largest Element in an Array - Tutorial

## Understanding the Problem
Given an array and an integer k, find the kth largest element in the array (not necessarily distinct).

## Visual Example
nums = [3,2,1,5,6,4], k = 2
Sorted: [1,2,3,4,5,6] → 2nd largest is 5

## Approaches
### 1. Min-Heap (Priority Queue)
- Maintain a min-heap of size k.
- For each number, add to heap. If heap size > k, remove smallest.
- The root of the heap is the kth largest.
- Time: O(N log k)

### 2. QuickSelect (Partition)
- Use QuickSelect to partition the array so the kth largest is at index N-k.
- Average O(N) time, worst O(N^2).

### 3. Sorting
- Sort the array and return nums[N-k].
- Time: O(N log N)

## Time/Space Complexity
- Heap: O(N log k) time, O(k) space
- QuickSelect: O(N) average time, O(1) space
- Sorting: O(N log N) time, O(1) extra space

## Key Concepts
- Heap for efficient k-selection
- QuickSelect for optimal time

## Edge Cases
- k = 1 (max element)
- k = nums.length (min element)
- Duplicates in array

## Optimization Notes
- Heap is best for streaming or partial data
- QuickSelect is best for in-place, one-time queries

*No code in this tutorial section.*

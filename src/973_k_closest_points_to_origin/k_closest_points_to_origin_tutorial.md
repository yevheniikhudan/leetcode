# K Closest Points to Origin - Tutorial

## Understanding the Problem
Given a list of points in the 2D plane and an integer k, we need to find the k points closest to the origin (0, 0) using Euclidean distance.

## Visual Example
Suppose points = [[1,3],[-2,2],[2,-2]], k = 2:
- (1,3): distance = sqrt(1^2 + 3^2) = sqrt(10)
- (-2,2): distance = sqrt(4 + 4) = sqrt(8)
- (2,-2): distance = sqrt(4 + 4) = sqrt(8)

The two closest are (-2,2) and (2,-2).

## Approaches
### 1. Sorting
- Compute the distance for each point.
- Sort all points by distance.
- Return the first k points.
- Time: O(N log N)

### 2. Max-Heap (Priority Queue)
- Use a max-heap of size k to keep the k closest points seen so far.
- For each point, if the heap has less than k points, add it.
- If the heap is full and the new point is closer, replace the farthest.
- Time: O(N log k)

### 3. QuickSelect (Partial Sort)
- Use QuickSelect to partition the array so the k closest points are in the first k positions.
- Time: Average O(N), Worst O(N^2)

## Time/Space Complexity
- Sorting: O(N log N) time, O(N) space
- Heap: O(N log k) time, O(k) space
- QuickSelect: O(N) average time, O(1) space

## Key Concepts
- Euclidean distance (no need to take sqrt, compare squared distances)
- Heap for efficient k-selection
- Partial sorting for optimal time

## Edge Cases
- k = points.length (return all)
- Points with same distance
- Negative coordinates

## Optimization Notes
- For large N and small k, heap is preferred.
- For small N, sorting is simple and effective.

*No code in this tutorial section.*

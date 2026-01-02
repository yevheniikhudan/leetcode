# 973. K Closest Points to Origin

**Difficulty:** Medium

## Topics
- Array
- Math
- Divide and Conquer
- Geometry
- Sorting
- Heap (Priority Queue)

## Problem Description
Given an array of `points` where `points[i] = [xi, yi]` represents a point on the X-Y plane and an integer `k`, return the `k` closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)^2 + (y1 - y2)^2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

### Example 1:
```
Input: points = [[1,3],[-2,2]], k = 1
Output: [[-2,2]]
Explanation: The distance from (1, 3) to the origin is sqrt(10).
The distance from (-2, 2) to the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
```

### Example 2:
```
Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
Explanation: The answer [[-2,4],[3,3]] would also be accepted.
```

## Constraints
- 1 <= k <= points.length <= 10^4
- -10^4 < xi, yi < 10^4

## Related Problems
- 215. Kth Largest Element in an Array
- 973. K Closest Points to Origin

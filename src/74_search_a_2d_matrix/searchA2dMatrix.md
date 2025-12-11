# 74. Search a 2D Matrix

## Problem Description

You are given an `m x n` integer matrix `matrix` with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer `target`, return `true` if `target` is in `matrix` or `false` otherwise.

You must write a solution in `O(log(m * n))` time complexity.

## Examples

### Example 1:
```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Matrix visualization:
 1   3   5   7
10  11  16  20
23  30  34  60
```

### Example 2:
```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

## Constraints

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 100`
- `-10^4 <= matrix[i][j], target <= 10^4`

## Topics

- Array
- Binary Search
- Matrix

## Difficulty

Medium

## Companies

Amazon, Google, Microsoft, Facebook, Apple, Bloomberg, Adobe, LinkedIn, Uber

## Similar Problems

- Search a 2D Matrix II (Medium)
- Binary Search (Easy)
- Search in Rotated Sorted Array (Medium)

## Hints

1. Think of the 2D matrix as a 1D sorted array.
2. Can you map 2D coordinates to 1D index and vice versa?
3. Use binary search on this "virtual" 1D array.

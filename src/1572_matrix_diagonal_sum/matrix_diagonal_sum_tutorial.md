# Matrix Diagonal Sum - Tutorial

## Understanding the Problem
Given a square matrix, sum all elements on the primary diagonal and all elements on the secondary diagonal, but do not double-count the center if n is odd.

## Visual Example
mat = [[1,2,3],[4,5,6],[7,8,9]]
- Primary diagonal: 1, 5, 9
- Secondary diagonal: 3, 5, 7
- Center (5) is counted only once
- Total: 1 + 5 + 9 + 3 + 7 = 25

## Approaches
### 1. Simple Loop
- Loop i from 0 to n-1
- Add mat[i][i] (primary)
- Add mat[i][n-1-i] (secondary)
- If n is odd, subtract the center once

## Time/Space Complexity
- O(N) time, O(1) space

## Key Concepts
- Matrix indexing
- Avoiding double-counting center

## Edge Cases
- n = 1 (single element)
- All elements the same

*No code in this tutorial section.*

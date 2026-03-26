# 54. Spiral Matrix

**Difficulty:** Medium

**Topics:** Array, Matrix, Simulation

## Problem Description

Given an `m x n` `matrix`, return all elements of the `matrix` in spiral order.

## Examples

### Example 1
```text
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```

Walkthrough:
```
1 → 2 → 3
        ↓
4 → 5   6
↑       ↓
7 ← 8 ← 9
```

### Example 2
```text
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

Walkthrough:
```
1 → 2 → 3 → 4
            ↓
5 → 6 → 7   8
        ↑   ↓
9 → 10← 11← 12
```

## Constraints

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 10`
- `-100 <= matrix[i][j] <= 100`

## Related Problems

- [54. Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/) (Medium)
- [54. Spiral Matrix III](https://leetcode.com/problems/spiral-matrix-iii/) (Medium)
- [54. Spiral Matrix IV](https://leetcode.com/problems/spiral-matrix-iv/) (Medium)

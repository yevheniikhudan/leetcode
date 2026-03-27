# 73. Set Matrix Zeroes

**Difficulty:** Medium

**Topics:** Array, Hash Table, Matrix

## Problem Description

Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`.

You must do it in-place.

## Examples

### Example 1

```text
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
```

### Example 2

```text
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

## Constraints

- `m == matrix.length`
- `n == matrix[0].length`
- `1 <= m, n <= 200`
- `-2^31 <= matrix[i][j] <= 2^31 - 1`

## Follow-up

- A straightforward approach using additional memory is possible.
- Can you solve it using constant extra space?

## Related Problems

- [289. Game of Life](https://leetcode.com/problems/game-of-life/) (Medium)
- [54. Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) (Medium)
- [48. Rotate Image](https://leetcode.com/problems/rotate-image/) (Medium)

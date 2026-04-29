# 3225. Maximum Score From Grid Operations

Difficulty: Hard

Topics: Array, Dynamic Programming, Matrix, Prefix Sum

## Problem

You are given a 2D matrix `grid` of size `n x n`. Initially, all cells of the grid are colored white.

In one operation, you can select any cell of indices `(i, j)`, and color black all the cells of the `jth` column starting from the top row down to the `ith` row.

The grid score is the sum of all `grid[i][j]` such that cell `(i, j)` is white and it has a horizontally adjacent black cell.

Return the maximum score that can be achieved after some number of operations.

## Examples

### Example 1

```text
Input: grid = [[0,0,0,0,0],[0,0,3,0,0],[0,1,0,0,0],[5,0,0,3,0],[0,0,0,0,2]]
Output: 11
```

Explanation: Color column `1` down to row `3`, and column `4` down to the last row. The score is `grid[3][0] + grid[1][2] + grid[3][3] = 11`.

### Example 2

```text
Input: grid = [[10,9,0,0,15],[7,1,0,8,0],[5,20,0,11,0],[0,0,0,1,2],[8,12,1,10,3]]
Output: 94
```

Explanation: Operations are performed on columns `1`, `2`, and `3` down to rows `1`, `4`, and `0`, respectively. The resulting score is `94`.

## Constraints

- `1 <= n == grid.length <= 100`
- `n == grid[i].length`
- `0 <= grid[i][j] <= 10^9`

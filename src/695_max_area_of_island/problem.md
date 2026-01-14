# 695. Max Area of Island

[LeetCode Link](https://leetcode.com/problems/max-area-of-island/description/)

Given a non-empty 2D binary matrix grid of 0's (water) and 1's (land), an island is a group of 1's connected 4-directionally (horizontal or vertical). You may assume all four edges of the grid are surrounded by water.

Return the maximum area of an island in the given 2D array. If there is no island, return 0.

**Example:**

Input:
```
grid = [
  [0,0,1,0,0,0,0,1,0,0,0,0,0],
  [0,0,0,0,0,0,0,1,1,1,0,0,0],
  [0,1,1,0,1,0,0,0,0,0,0,0,0],
  [0,1,0,0,1,1,0,0,1,0,1,0,0],
  [0,1,0,0,1,1,0,0,1,1,1,0,0],
  [0,0,0,0,0,0,0,0,0,0,1,0,0]
]
```
Output: 6

**Constraints:**
- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 50
- grid[i][j] is either 0 or 1.

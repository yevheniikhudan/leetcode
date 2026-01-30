# 62. Unique Paths

**Difficulty:** Medium

**Topics:** Math, Dynamic Programming, Combinatorics

## Problem Description

There is a robot on an `m x n` grid. The robot is initially located at the top-left corner (i.e., `grid[0][0]`). The robot tries to move to the bottom-right corner (i.e., `grid[m - 1][n - 1]`). The robot can only move either down or right at any point in time.

Given the two integers `m` and `n`, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to `2 * 10^9`.

## Examples

### Example 1

**Input:** m = 3, n = 7  
**Output:** 28

### Example 2

**Input:** m = 3, n = 2  
**Output:** 3  
**Explanation:** From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:  
1. Right -> Down -> Down  
2. Down -> Down -> Right  
3. Down -> Right -> Down

## Constraints

- `1 <= m, n <= 100`

## Related Problems

- [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/) - Medium
- [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) - Medium
- [Dungeon Game](https://leetcode.com/problems/dungeon-game/) - Hard
- [Minimum Path Cost in a Grid](https://leetcode.com/problems/minimum-path-cost-in-a-grid/) - Medium
- [Minimum Cost Homecoming of a Robot in a Grid](https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/) - Medium
- [Number of Ways to Reach a Position After Exactly k Steps](https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/) - Medium
- [Paths in Matrix Whose Sum Is Divisible by K](https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/) - Hard

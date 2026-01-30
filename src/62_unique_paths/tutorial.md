# Tutorial: Unique Paths

## Understanding the Problem

The problem involves a robot navigating a grid from the top-left corner to the bottom-right corner, moving only right or down. We need to count the unique paths. This is a classic combinatorics problem where the number of paths equals the binomial coefficient C(m+n-2, m-1), representing the ways to choose 'right' moves out of total moves.

## Visual Examples

Consider a 3x2 grid (m=3, n=2):

```
Start → → ↓
      ↓ ↓ ↓
      → ↓ End
```

Paths:
1. Right, Right, Down
2. Right, Down, Right
3. Down, Right, Right

Total: 3 paths.

For 3x7, it's C(8,2) = 28.

## Approaches

### 1. Combinatorics (Most Efficient)
- **Idea**: Total moves: (m-1) down + (n-1) right = m+n-2 moves. Choose (m-1) positions for down moves.
- **Formula**: C(m+n-2, m-1) = C(m+n-2, n-1)
- **Implementation**: Compute binomial coefficient iteratively to avoid overflow.
- **Time Complexity**: O(min(m, n))
- **Space Complexity**: O(1)

### 2. Dynamic Programming
- **Idea**: dp[i][j] = number of ways to reach (i,j). dp[i][j] = dp[i-1][j] + dp[i][j-1]
- **Base**: dp[0][j] = 1, dp[i][0] = 1
- **Time Complexity**: O(m * n)
- **Space Complexity**: O(m * n) or O(n) optimized

### 3. Recursive with Memoization
- **Idea**: Recurse with memo for each cell.
- **Time/Space**: O(m * n)

## Key Concepts and Patterns
- **Grid Path Counting**: Use DP or combinatorics for grid problems.
- **Binomial Coefficient**: Essential for counting combinations without order.
- **Optimization**: Combinatorics is fastest; DP for larger grids if needed.

## Edge Cases and Common Pitfalls
- **m=1 or n=1**: Only 1 path (all right or all down).
- **Large m,n**: Use long for results; iterative binomial to avoid recursion depth.
- **Pitfall**: Integer overflow; use long in Java/C++.

## Optimization Notes
- Prefer combinatorics for speed.
- In DP, use 1D array to save space.
- For very large grids, consider BigInteger if constraints allow.

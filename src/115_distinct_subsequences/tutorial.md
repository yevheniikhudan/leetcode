# Tutorial: Distinct Subsequences

## Understanding the Problem

The problem asks to count the number of distinct subsequences of string `s` that exactly match string `t`. A subsequence is derived from `s` by deleting some or no elements without changing the order of the remaining elements.

For example, "rabbit" can be formed from "rabbbit" by selecting specific characters in order.

## Visual Examples

For s = "rabbbit", t = "rabbit":

- Positions: r a b b b i t
- For t[0]='r', match s[0]
- t[1]='a', match s[1]
- t[2]='b', can match s[2], s[3], or s[4]
- And so on, leading to 3 ways.

For s = "babgbag", t = "bag": 5 ways, as shown.

## Approaches

### 1. Recursion with Memoization
- Use a recursive function with indices i (for s), j (for t).
- If j == len(t), return 1 (found a match).
- If i == len(s), return 0 (no more chars in s).
- If s[i] == t[j], can take it (recurse i+1, j+1) or skip (recurse i+1, j).
- Else, skip (recurse i+1, j).
- Memoize on (i,j).

### 2. Dynamic Programming (2D Table)
- Create dp[m+1][n+1], where m = len(s), n = len(t).
- dp[i][j] = number of ways to match s[0..i-1] with t[0..j-1].
- Initialize dp[0][0] = 1.
- For each i,j, if s[i-1] == t[j-1], dp[i][j] = dp[i-1][j-1] + dp[i-1][j] (take or skip).
- Else, dp[i][j] = dp[i-1][j] (skip).
- Return dp[m][n].

### 3. 1D DP (Space Optimized)
- Use two arrays or one, updating row by row.

## Time and Space Complexity

- Recursion: O(m*n) time, O(m*n) space.
- DP: O(m*n) time, O(m*n) space (or O(n) with 1D).

Since m,n <=1000, O(10^6) is fine.

## Key Concepts and Patterns

- Subsequence Matching: Counting ways, not just existence.
- DP Transitions: Add when match, or skip.
- Memoization: Avoid recomputing subproblems.

## Edge Cases and Common Pitfalls

- t empty: 1 way (empty subsequence).
- s empty, t not: 0.
- s shorter than t: 0.
- All matches: C(m, n) if s has enough chars.
- Duplicates: Multiple ways to choose positions.

## Optimization Notes

- Use 1D DP for space: prev and curr arrays.
- In recursion, ensure no stack overflow (1000 depth, but memo helps).

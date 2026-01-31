# Tutorial: Longest Common Subsequence

## Understanding the Problem

Find the length of the longest subsequence present in both strings, maintaining order but not necessarily contiguous. This is a classic DP problem for string comparison.

## Visual Examples

For text1 = "abcde", text2 = "ace":

DP Table:

|   |   | a | c | e |
|---|---|---|---|---|
|   | 0 | 0 | 0 | 0 |
| a | 0 | 1 | 1 | 1 |
| b | 0 | 1 | 1 | 1 |
| c | 0 | 1 | 2 | 2 |
| d | 0 | 1 | 2 | 2 |
| e | 0 | 1 | 2 | 3 |

LCS length: 3 ("ace").

## Approaches

### 1. Dynamic Programming (Most Efficient)
- **Idea**: dp[i][j] = LCS length for text1[0..i-1] and text2[0..j-1].
- **Transition**: If text1[i-1] == text2[j-1], dp[i][j] = dp[i-1][j-1] + 1; else max(dp[i-1][j], dp[i][j-1]).
- **Base**: dp[0][j] = 0, dp[i][0] = 0.
- **Time Complexity**: O(m * n)
- **Space Complexity**: O(m * n)

### 2. Space Optimized DP
- **Idea**: Use two arrays or one, updating row by row.
- **Time**: O(m * n)
- **Space**: O(min(m, n))

### 3. Recursive with Memoization
- **Idea**: Recurse on substrings, memoize results.
- **Time/Space**: O(m * n)

## Key Concepts and Patterns
- **DP for Strings**: Build table for substring problems.
- **Subsequence vs Substring**: Order matters, not contiguity.
- **Optimization**: Space reduction for large strings.

## Edge Cases and Common Pitfalls
- **Empty Strings**: If either is empty, LCS = 0.
- **No Common Chars**: LCS = 0.
- **Identical Strings**: LCS = length.
- **Pitfall**: Off-by-one in indices; use 1-based or careful slicing.

## Optimization Notes
- For very large strings, consider space optimization.
- If needing the subsequence itself, modify DP to track choices.

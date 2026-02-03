# Tutorial: Interleaving String

## Understanding the Problem

The problem asks whether string `s3` can be formed by interleaving strings `s1` and `s2`. This means merging `s1` and `s2` by taking characters alternately from each, maintaining their relative order. For example, if s1 = "ab" and s2 = "cd", possible interleavings are "abcd", "acbd", "cabd", etc., but not "adbc" since 'b' and 'c' are out of order.

First, check if `len(s3) == len(s1) + len(s2)`. If not, return false immediately.

## Visual Examples

Consider s1 = "ab", s2 = "cd", s3 = "acbd".

- Start with pointers i=0, j=0 for s1 and s2.
- s3[0]='a' matches s1[0]='a', so take from s1, i=1.
- s3[1]='c' matches s2[0]='c', so take from s2, j=1.
- s3[2]='b' matches s1[1]='b', so take from s1, i=2.
- s3[3]='d' matches s2[1]='d', so take from s2, j=2.
- Success.

For s3 = "adbc", it would fail because 'b' and 'c' can't be matched in order.

## Approaches

### 1. Recursion with Memoization
- Use a recursive function with parameters i, j (indices in s1 and s2).
- At each step, if s3[i+j] matches s1[i], recurse on i+1, j.
- If matches s2[j], recurse on i, j+1.
- Base case: if i == len(s1) and j == len(s2), return true.
- Memoize on (i,j) to avoid recomputation.

### 2. Dynamic Programming (2D Table)
- Create a 2D boolean array dp[m+1][n+1], where m = len(s1), n = len(s2).
- dp[i][j] = true if the first i chars of s1 and first j of s2 can form the first i+j of s3.
- Initialize dp[0][0] = true.
- For each i,j, if dp[i][j] is true, and s3[i+j] == s1[i], set dp[i+1][j] = true.
- Similarly for s2[j].
- Return dp[m][n].

### 3. Breadth-First Search (BFS)
- Use a queue to store pairs (i,j).
- Start with (0,0), mark visited.
- For each, try moving to (i+1,j) if s3[i+j] == s1[i], or (i,j+1) if == s2[j].
- If reach (m,n), return true.

## Time and Space Complexity

- Recursion with Memo: O(m*n) time and space.
- DP: O(m*n) time, O(m*n) space (can optimize to O(min(m,n)) with 1D array).
- BFS: O(m*n) time, O(m*n) space for queue and visited.

Since m,n <= 100, all are fine.

## Key Concepts and Patterns

- Pointers/Indices Tracking: Managing positions in s1, s2, s3.
- Matching Characters: At each step, choose to advance in s1 or s2 if the character matches.
- Memoization/DP: Avoid exponential time by caching states.
- Length Check: Essential first step.

## Edge Cases and Common Pitfalls

- Empty strings: If s1 and s2 are empty, s3 must be empty.
- One string empty: If s1 is empty, check if s2 == s3.
- Length mismatch: Always check len(s3) == len(s1) + len(s2).
- Duplicate characters: Order matters, not just counts (e.g., s1="aa", s2="a", s3="aaa" vs "aaa").
- Index out of bounds: Ensure i < m and j < n before accessing.

## Optimization Notes

- For space, use 1D DP: Iterate over rows, keeping previous row.
- Follow-up asks for O(min(m,n)) space, achievable with 1D DP or BFS with set for visited.
- In practice, DP is simplest and efficient.

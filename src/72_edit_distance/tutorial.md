# Tutorial: Edit Distance

## Understanding the Problem

The problem requires finding the minimum number of operations (insert, delete, replace) to transform one string into another. This is the Levenshtein distance.

Operations:
- Insert: Add a character to word1.
- Delete: Remove a character from word1.
- Replace: Change a character in word1 to match word2.

The goal is the minimum steps to make word1 equal word2.

## Visual Examples

For word1 = "horse", word2 = "ros":

- Replace 'h' with 'r': "rorse"
- Delete 'r': "rose"
- Delete 'e': "ros"
- Total: 3 operations.

For word1 = "kitten", word2 = "sitting":

- Replace 'k' with 's': "sitten"
- Replace 'e' with 'i': "sittin"
- Insert 'g': "sitting"
- Total: 3.

## Approaches

### 1. Recursion with Memoization
- Use a recursive function with indices i (for word1), j (for word2).
- If i == len(word1), return len(word2) - j (insert remaining).
- If j == len(word2), return len(word1) - i (delete remaining).
- If word1[i] == word2[j], recurse i+1, j+1.
- Else, min of: replace (1 + recurse i+1, j+1), insert (1 + recurse i, j+1), delete (1 + recurse i+1, j).
- Memoize on (i,j).

### 2. Dynamic Programming (2D Table)
- Create dp[m+1][n+1], where m = len(word1), n = len(word2).
- dp[i][j] = min operations for word1[0..i-1] and word2[0..j-1].
- Initialize dp[i][0] = i (delete all), dp[0][j] = j (insert all).
- For each i,j, if word1[i-1] == word2[j-1], dp[i][j] = dp[i-1][j-1].
- Else, dp[i][j] = 1 + min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]).
- Return dp[m][n].

### 3. 1D DP (Space Optimized)
- Use two arrays, prev and curr, updating row by row.

## Time and Space Complexity

- Recursion: O(m*n) time, O(m*n) space.
- DP: O(m*n) time, O(m*n) space (or O(min(m,n)) with 1D).

Since m,n <=500, O(250,000) is fine.

## Key Concepts and Patterns

- DP on strings: Subproblems for prefixes.
- Choices: Match, replace, insert, delete.
- Base cases: Empty strings.

## Edge Cases and Common Pitfalls

- One string empty: Operations = length of other.
- Identical strings: 0.
- Single character differences: 1.
- Long strings: Ensure no TLE, use DP.
- Case sensitivity: All lowercase, fine.

## Optimization Notes

- Use 1D DP for space.
- In recursion, memo prevents exponential time.

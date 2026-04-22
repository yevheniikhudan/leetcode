# Words Within Two Edits of Dictionary - Tutorial

## Understanding the Problem

We need to find which words from a list are "close" to a pattern word. Closeness is measured by **edit distance** (also called Levenshtein distance) - the minimum number of single-character edits required to transform one string into another.

### What Counts as an Edit?

1. **Insert** a character: "cat" → "cart" (insert 'r')
2. **Delete** a character: "cart" → "cat" (delete 'r')
3. **Replace** a character: "cat" → "bat" (replace 'c' with 'b')

Words that need **0, 1, or 2 edits** should be returned.

## Approach 1: Brute Force with Edit Distance

### Concept

For each word in the queries:
1. Calculate the edit distance between the word and the pattern
2. If distance ≤ 2, add the word to the result
3. Return the result array

### How to Calculate Edit Distance

Use **dynamic programming**:
- Create a 2D table where `dp[i][j]` represents the edit distance between the first `i` characters of word A and the first `j` characters of word B
- Fill the table bottom-up:
  - If characters match: `dp[i][j] = dp[i-1][j-1]`
  - If they don't match: `dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])`
    - `dp[i-1][j] + 1` = delete from word A
    - `dp[i][j-1] + 1` = insert into word A
    - `dp[i-1][j-1] + 1` = replace

### Visual Example

Computing edit distance between "hello" and "hallo":

```
    ""  h  a  l  l  o
""   0  1  2  3  4  5
h    1  0  1  2  3  4
e    2  1  1  2  3  4
l    3  2  2  1  2  3
l    4  3  3  2  1  2
o    5  4  4  3  2  1
```

The value at `dp[5][5] = 1`, so "hello" to "hallo" requires 1 edit ✓

## Approach 2: Optimized Edit Distance

Since we only care if distance ≤ 2, we can **stop early** once the distance exceeds 2. This prunes unnecessary computation.

### Key Optimization

When building the DP table:
- If all values in a row are > 2, we can stop early and mark this word as "not within 2 edits"
- Use a rolling array to save space (only store 2 rows instead of entire matrix)

## Edge Cases & Pitfalls

1. **Empty strings:** Handle edge cases with different lengths
2. **Same word:** "hello" to "hello" = 0 edits ✓ (include in result)
3. **Complete mismatch:** "abc" to "xyz" = 3 edits ✗ (do NOT include)
4. **Length difference:** "cat" to "cart" requires 1 edit (insertion)
5. **Case sensitivity:** Problem specifies lowercase, so no special handling needed

## Complexity Analysis

**Time Complexity:**
- Brute force: O(N × M × P) where N = number of queries, M = average word length, P = pattern length
- Optimized: O(N × M × P) worst case, but with early termination when distance > 2

**Space Complexity:**
- O(M × P) for full DP table, or O(min(M, P)) with optimized rolling array

## Summary

The problem asks us to return words within edit distance 2 from a pattern. The standard approach uses dynamic programming to compute edit distance for each word, then filters and returns those with distance ≤ 2.

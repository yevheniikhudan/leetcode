# Tutorial: Check If Two String Arrays are Equivalent

## Understanding the Problem
Given two arrays of strings, check if their concatenations are equal.

## Visual Example
- word1 = ["ab", "c"], word2 = ["a", "bc"] → "abc" == "abc" (true)
- word1 = ["a", "cb"], word2 = ["ab", "c"] → "acb" != "abc" (false)

## Approaches
### 1. Concatenate and Compare (Most Efficient)
- Join all strings in each array and compare the results.
- Time: O(N+M), Space: O(N+M)

### 2. Two Pointer Character-by-Character
- Use two pointers to iterate through both arrays character by character, comparing as you go.
- Time: O(N+M), Space: O(1)

## Complexity
- Both approaches: O(N+M) time, where N and M are the total lengths of word1 and word2.
- Concatenate: O(N+M) space. Two pointer: O(1) space.

## Edge Cases
- Empty arrays.
- Arrays with empty strings.

## Optimization Notes
- The two-pointer approach is optimal for space, but concatenation is simpler and efficient for most cases.

# 1768. Merge Strings Alternately - Tutorial

This problem is a simple string manipulation task. The goal is to merge two strings by alternating their characters, starting with the first string. If one string is longer, append the remaining characters at the end.

## Approach Outline
1. Initialize an empty result string or list.
2. Use a loop to iterate over the indices of both strings up to the length of the longer string.
3. At each step, if the current index is within the bounds of word1, append its character to the result.
4. If the current index is within the bounds of word2, append its character to the result.
5. After the loop, return the merged string.

This approach works in O(n + m) time, where n and m are the lengths of the two strings. No advanced data structures are needed.

# Longest Palindromic Substring - Tutorial

## Understanding the Problem

A palindrome is a string that reads the same forwards and backwards. For example, "aba" and "bb" are palindromes. The task is to find the longest contiguous substring within the given string that forms a palindrome.

Key points:
- We need the longest palindromic substring, not just any palindrome
- If there are multiple of the same length, any one is acceptable
- Single characters are always palindromes
- The string can contain digits and letters

## Approach 1: Brute Force

### Strategy
Check every possible substring to see if it's a palindrome, keeping track of the longest one found.

### Time Complexity: O(n^3)
- O(n^2) substrings to check
- O(n) time to verify each substring is a palindrome

### Space Complexity: O(1)

### Why Inefficient
Too slow for n=1000, as 1000^3 = 10^9 operations.

## Approach 2: Dynamic Programming

### Strategy
Use a 2D DP table where dp[i][j] is true if substring s[i..j] is a palindrome.

- Base case: dp[i][i] = true (single characters)
- dp[i][i+1] = true if s[i] == s[i+1] (two characters)
- For length > 2: dp[i][j] = (s[i] == s[j]) and dp[i+1][j-1]

Track the maximum length and starting index.

### Time Complexity: O(n^2)
### Space Complexity: O(n^2)

### Advantages
Clear and straightforward, good for understanding.

## Approach 3: Expand Around Center (Optimal)

### Strategy
Every palindrome has a center (single character for odd length, between two characters for even length).

For each possible center:
1. Expand outwards as long as characters match
2. Track the longest palindrome found

Handle both odd and even length palindromes by checking two types of centers.

### Time Complexity: O(n^2)
### Space Complexity: O(1)

### Visual Example
For "babad":
- Center at 'a' (index 2): expands to "aba"
- Center between 'b' and 'a' (indices 1-2): expands to "bab"

### Why Optimal
O(n^2) time is acceptable for n=1000, and O(1) space is efficient.

## Edge Cases

- Single character: return the character
- All same characters: entire string is palindrome
- No palindromes longer than 1: return any single character
- Even length palindromes: "aa", "abba"
- Odd length palindromes: "aba", "racecar"

## Common Pitfalls

- Forgetting to handle both odd and even length centers
- Not updating the result when a longer palindrome is found
- Incorrect substring extraction (off-by-one errors)

## Optimization Notes

- The expand around center approach is usually the fastest in practice
- For very large constraints, Manacher's algorithm could be used (O(n) time)
- Always return the substring, not just the length

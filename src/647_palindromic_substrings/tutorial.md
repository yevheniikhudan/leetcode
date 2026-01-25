# Palindromic Substrings - Tutorial

## Understanding the Problem

We need to count all contiguous substrings in a string that are palindromes. A palindrome reads the same forwards and backwards. Every single character is a palindrome, and longer palindromes are built from these.

Key points:
- Count all palindromic substrings, not just the longest
- Substrings must be contiguous
- Single characters always count
- Overlapping substrings are counted separately

## Approach 1: Brute Force

### Strategy
Check every possible substring (O(n²) substrings) and verify if it's a palindrome (O(n) per check).

### Time Complexity: O(n^3)
### Space Complexity: O(1)

### Why Inefficient
Too slow for n=1000.

## Approach 2: Dynamic Programming

### Strategy
Use a 2D DP table where dp[i][j] is true if s[i..j] is a palindrome.

- Base: dp[i][i] = true, count++
- For length 2: if s[i] == s[i+1], dp[i][i+1] = true, count++
- For length > 2: dp[i][j] = (s[i] == s[j]) and dp[i+1][j-1], if true, count++

### Time Complexity: O(n^2)
### Space Complexity: O(n^2)

### Advantages
Straightforward and counts as we go.

## Approach 3: Expand Around Center (Optimal)

### Strategy
For each possible center, expand outwards and count the palindromes found.

- Odd length: center at each character
- Even length: center between characters
- Each expansion step finds a new palindrome

### Time Complexity: O(n^2)
### Space Complexity: O(1)

### Visual Example
For "aaa":
- Center at index 0: expands to "a", "aaa" (but "aa" in between)
- Actually, counts each expansion.

### Why Optimal
O(n^2) time, O(1) space, and directly counts without extra storage.

## Edge Cases

- Single character: 1
- All same characters: n(n+1)/2
- No palindromes longer than 1: n
- Empty string: 0 (but constraints say 1 <= n)

## Common Pitfalls

- Double-counting substrings
- Forgetting to count single characters
- Incorrect expansion logic

## Optimization Notes

- Expand around center is efficient and easy to implement
- DP gives the same time but uses more space
- For counting, expand around center is preferred

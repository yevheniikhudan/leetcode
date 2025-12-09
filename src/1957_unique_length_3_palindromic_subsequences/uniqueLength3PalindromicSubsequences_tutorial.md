# Unique Length-3 Palindromic Subsequences - Tutorial

## Key Insights
- A palindrome of length 3 has the pattern: XYX (where X is the first and last character)
- For each character X (a-z), find the first and last occurrence
- Count unique characters Y that appear between the first and last occurrence of X
- Total palindromes = sum of unique middle characters for each outer character

## Steps
1. For each character 'a' to 'z':
   - Find the first occurrence index
   - Find the last occurrence index
   - If they exist and are different (at least 2 positions apart):
     - Count unique characters between first and last occurrence
     - Add to result

2. Use a set to track unique middle characters for each outer character

## Example
For s = "aabca":
- Character 'a': first=0, last=4, middle chars={'a','b','c'} → 3 palindromes
- Character 'b': first=1, last=1 → skip (same position)
- Character 'c': first=3, last=3 → skip (same position)
- Total: 3

For s = "bbcbaba":
- Character 'a': first=4, last=6, middle chars={'b'} → 1 palindrome ("aba")
- Character 'b': first=0, last=5, middle chars={'b','c','a'} → 3 palindromes ("bbb","bcb","bab")
- Character 'c': first=2, last=2 → skip
- Total: 4

## Implementation
- Time complexity: O(26 * n) = O(n)
- Space complexity: O(26) = O(1)

## Edge Cases
- String with all same characters: only 1 palindrome
- String with no repeated characters: 0 palindromes
- Minimum length string (3 chars): check if palindrome

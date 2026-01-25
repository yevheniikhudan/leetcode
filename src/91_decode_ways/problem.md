# 91. Decode Ways

## Medium

**Topics:** String, Dynamic Programming

**Companies:** Amazon, Microsoft, Google, Facebook, Apple, Bloomberg

## Problem Description

Given a string `s` containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return `0`.

The mapping is as follows:
- "1" -> 'A'
- "2" -> 'B'
- ...
- "25" -> 'Y'
- "26" -> 'Z'

Note: "0" cannot be decoded on its own, but can be part of "10" or "20".

## Examples

### Example 1:
```
Input: s = "12"
Output: 2
Explanation: "AB" (1 2) or "L" (12)
```

### Example 2:
```
Input: s = "226"
Output: 3
Explanation: "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6)
```

### Example 3:
```
Input: s = "06"
Output: 0
Explanation: "06" cannot be decoded
```

## Constraints

- `1 <= s.length <= 100`
- `s` contains only digits and may contain leading zero(s).

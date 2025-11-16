# Number of Substrings With Only 1s

**Difficulty:** Medium
**Topics:** String, Counting
**Source:** [LeetCode](https://leetcode.com/problems/number-of-substrings-with-only-1s/)

## Problem Description

Given a binary string `s` (consisting only of '0's and '1's), return the number of substrings that contain only '1's.

A substring is a contiguous sequence of characters within the string.

## Examples

### Example 1:
```
Input: s = "0110111"
Output: 9
Explanation: Substrings with only '1's are:
"1", "1", "1", "1", "1", "11", "11", "111", "11"
```

### Example 2:
```
Input: s = "101"
Output: 2
Explanation: Substrings with only '1's are: "1", "1"
```

## Constraints
- `1 <= s.length <= 10^5`
- `s[i]` is either `'0'` or `'1'`.

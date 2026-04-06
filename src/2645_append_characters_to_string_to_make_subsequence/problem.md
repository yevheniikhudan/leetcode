# 2645. Append Characters to String to Make Subsequence

**Difficulty:** Medium  
**Topics:** String, Greedy, Two Pointers

---

## Problem Description

You are given two strings `s` and `t` consisting of only lowercase English letters.

Return the **minimum number of characters that need to be appended** to the end of `s` so that `t` becomes a subsequence of `s`.

A **subsequence** is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

---

## Examples

### Example 1:
```
Input: s = "coaching", t = "coding"
Output: 4
Explanation: 
Append the characters "ding" to the end of "coaching" to get "coachingding".
Now t = "coding" is a subsequence of "coachingding" (['c' from position 0, 'o' from position 1, 'd' from position 12, 'i' from position 13, 'n' from position 14, 'g' from position 15]).
The answer is 4.
```

### Example 2:
```
Input: s = "abcde", t = "a"
Output: 0
Explanation: t = "a" is already a subsequence of s = "abcde".
```

### Example 3:
```
Input: s = "z", t = "abcde"
Output: 5
Explanation: You need to append "abcde" to the end of "z" to make t a subsequence.
```

---

## Constraints

- `1 <= s.length <= 10^5`
- `1 <= t.length <= 10^5`
- `s` and `t` consist of only lowercase English letters

---

## Related Problems

- LeetCode 392 - Is Subsequence
- LeetCode 1143 - Longest Common Subsequence
- LeetCode 115 - Distinct Subsequences

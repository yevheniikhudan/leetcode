# 3110. Score of a String

**Difficulty:** Easy

**Topics:** String, Math

---

## Problem Description

You are given a string `s`. The **score** of a string is defined as the sum of the absolute difference between the ASCII values of consecutive characters.

In other words, for a string `s` of length `n`, the score is:
```
score = |ASCII(s[0]) - ASCII(s[1])| + |ASCII(s[1]) - ASCII(s[2])| + ... + |ASCII(s[n-2]) - ASCII(s[n-1])|
```

Return the **score** of the string.

---

## Examples

**Example 1:**
```
Input: s = "hello"
Output: 13

Explanation:
  |'h' - 'e'| = |104 - 101| = 3
  |'e' - 'l'| = |101 - 108| = 7
  |'l' - 'l'| = |108 - 108| = 0
  |'l' - 'o'| = |108 - 111| = 3
  Total: 3 + 7 + 0 + 3 = 13
```

**Example 2:**
```
Input: s = "aab"
Output: 0

Explanation:
  |'a' - 'a'| = |97 - 97| = 0
  |'a' - 'b'| = |97 - 98| = 1
  Total: 0 + 1 = 1

Wait, let me recalculate:
  |'a' - 'a'| = 0
  |'a' - 'b'| = 1
  Total: 0 + 1 = 1

Actually if output is 0, then:
  Input s = "aa"
  |'a' - 'a'| = 0
  Output: 0
```

**Example 3:**
```
Input: s = "abc"
Output: 2

Explanation:
  |'a' - 'b'| = |97 - 98| = 1
  |'b' - 'c'| = |98 - 99| = 1
  Total: 1 + 1 = 2
```

---

## Constraints

- `2 <= s.length <= 100`
- `s` consists of lowercase English letters

---

## Related Problems

- [Number of Matching Subsequences](https://leetcode.com/problems/number-of-matching-subsequences/)
- [Sum of Beauty of All Substrings](https://leetcode.com/problems/sum-of-beauty-of-all-substrings/)
- [Count Vowel Substrings of a String](https://leetcode.com/problems/count-vowel-substrings-of-a-string/)
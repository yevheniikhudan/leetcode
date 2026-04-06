# 392. Is Subsequence

**Difficulty:** Easy

**Topics:** Two Pointers, String, Dynamic Programming

## Problem Description

Given two strings `s` and `t`, return `true` if `s` is a subsequence of `t`, or `false` otherwise.

A **subsequence** of a string is a new string that is formed from the original string by deleting some (not necessarily consecutive) characters without changing the relative order of the remaining characters.

## Examples

**Example 1:**
```
Input: s = "abc", t = "ahbgdc"
Output: true
```
Explanation: "abc" is a subsequence of "ahbgdc" (we can delete 'h' and 'g' from "ahbgdc" to get "abc").

**Example 2:**
```
Input: s = "axc", t = "ahbgdc"
Output: false
```
Explanation: "axc" is not a subsequence of "ahbgdc" because 'x' is not in "ahbgdc".

## Constraints

- `0 <= s.length <= 100`
- `0 <= t.length <= 10^4`
- `s` and `t` consist of lowercase English letters

## Related Problems

- 115. Distinct Subsequences
- 187. Repeated DNA Sequences
- 522. Longest Uncommon Subsequence II
- 524. Longest Word in Dictionary through Deleting Letters

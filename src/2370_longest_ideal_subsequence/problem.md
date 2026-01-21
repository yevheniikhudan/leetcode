# 2370. Longest Ideal Subsequence

[LeetCode link](https://leetcode.com/problems/longest-ideal-subsequence/description/)

Given a string `s` and an integer `k`, return the length of the longest ideal subsequence of `s`.
A subsequence is ideal if the absolute difference in the alphabet positions of every two adjacent letters is less than or equal to `k`.

- **Input:**
    - `s` (str): The input string.
    - `k` (int): The maximum allowed difference between adjacent letters.
- **Output:**
    - The length of the longest ideal subsequence.

**Example 1:**

Input: s = "acfgbd", k = 2
Output: 4
Explanation: The longest ideal subsequence is "acbd". The absolute difference between adjacent letters is always less than or equal to 2.

**Example 2:**

Input: s = "abcd", k = 3
Output: 4
Explanation: The whole string is an ideal subsequence.

**Constraints:**
- 1 <= s.length <= 10^5
- 0 <= k <= 25
- s consists of lowercase English letters.

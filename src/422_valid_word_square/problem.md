# 422. Valid Word Square

**Difficulty:** Medium

**Topics/Tags:** Array, String, Matrix

---

## Problem Description

Given an array of strings `words`, return `true` if it forms a valid word square.

A sequence of strings forms a valid word square if the k-th row and the k-th column read the same string for all `k` in the range `0 <= k < max(numRows, numColumns)`, where `numRows` is the number of strings and `numColumns` is the maximum length of any string.

**In other words:**  
If you write the words one beneath the other to form a grid, reading the k-th row should give you the exact same string as reading the k-th column for all valid `k`. For every position `(i, j)`, `words[i][j]` must equal `words[j][i]` whenever both are defined.

---

## Examples

### Example 1:
**Input:** `words = ["abcd", "bnrt", "crmy", "dtye"]`  
**Output:** `true`  
**Explanation:**  
```
  a b c d
  b n r t
  c r m y
  d t y e
```
Rows and columns both read "abcd", "bnrt", "crmy", "dtye".

### Example 2:
**Input:** `words = ["abcd", "bnrt", "crm", "dt"]`  
**Output:** `true`  
**Explanation:**  
```
  a b c d
  b n r t
  c r m
  d t
```
The 2nd column is "bnrt" but only "bn" are valid. The 3rd column is "crm" and the 3rd row is "crm", which match.

### Example 3:
**Input:** `words = ["ball", "area", "read", "lady"]`  
**Output:** `false`  
**Explanation:**  
```
  b a l l
  a r e a
  r e a d
  l a d y
```
The 3rd row reads "read" while the 3rd column reads "lead", which do not match.

---

## Constraints

- `1 <= words.length <= 500`
- `1 <= words[i].length <= 500`
- All strings consist of lowercase English letters only.

---

## Related Problems

- [Rotate Image](https://leetcode.com/problems/rotate-image/) (Similar matrix manipulation)
- [Transpose Matrix](https://leetcode.com/problems/transpose-matrix/) (Related concept)

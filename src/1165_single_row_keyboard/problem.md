# Single-Row Keyboard

**Difficulty:** Easy  
**Problem Number:** 1165

## Topics/Tags
- Hash Table
- String

## Problem Description

There is a special keyboard with all keys in a single row.

Given a **string `keyboard`** of length 26 indicating the layout of the keyboard (i.e., keyboard[0] is the leftmost key and keyboard[25] is the rightmost key), and a **string `word`**, return the total time to type `word` using the single-row keyboard.

The time to type a character is the **absolute difference** in the indices of the current and previous characters. The finger starts at index 0.

## Examples

### Example 1
**Input:**
```
keyboard = "abcdefghijklmnopqrstuvwxyz"
word = "cba"
```
**Output:**
```
4
```
**Explanation:**
- Start at index 0
- To type 'c', move from 0 to 2: |0 - 2| = 2
- To type 'b', move from 2 to 1: |2 - 1| = 1
- To type 'a', move from 1 to 0: |1 - 0| = 1
- Total = 2 + 1 + 1 = 4

### Example 2
**Input:**
```
keyboard = "pqrstuvwxyzabcdefghijklmno"
word = "leetcode"
```
**Output:**
```
73
```
**Explanation:**
Calculate the distance for each character in "leetcode" based on keyboard layout.

### Example 3
**Input:**
```
keyboard = "abcdefghijklmnopqrstuvwxyz"
word = "abc"
```
**Output:**
```
3
```
**Explanation:**
- Start at index 0
- To type 'a', move from 0 to 0: 0
- To type 'b', move from 0 to 1: 1
- To type 'c', move from 1 to 2: 1
- Total = 0 + 1 + 1 = 2

## Constraints

- `keyboard.length == 26`
- `keyboard` contains each English lowercase letter exactly once
- `1 <= word.length <= 10^4`
- `word[i]` is an English lowercase letter

## Related Problems

- Keyboard Row
- Minimum Time Typing on Virtual Keyboard

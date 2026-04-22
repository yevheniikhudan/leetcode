# Words Within Two Edits of Dictionary

**Difficulty:** Medium  
**Problem Number:** 2452

## Topics/Tags
- String
- Array
- Brute Force

## Problem Description

You are given an array of strings `queries` and a string `pattern`.

For each query, count how many words in the query are within **two edits** of the pattern. An edit is one of:
- Insert a character
- Delete a character
- Replace a character

Return an array of strings containing only the words that are within two edits of the pattern.

## Examples

### Example 1
**Input:**
```
queries = ["hello","hallo","hxllo"]
pattern = "hello"
```
**Output:**
```
["hello","hallo"]
```
**Explanation:**
- "hello" has 0 edits from "hello" ✓
- "hallo" has 1 edit (replace 'e' with 'a') ✓
- "hxllo" has 2 edits (replace 'e' with 'x') but still within 2 edits ✓

### Example 2
**Input:**
```
queries = ["abc","ab","bc"]
pattern = "abc"
```
**Output:**
```
["abc","ab","bc"]
```
**Explanation:**
- "abc" has 0 edits from "abc" ✓
- "ab" has 1 edit (delete 'c') ✓
- "bc" has 1 edit (delete 'a') ✓

## Constraints

- `1 <= pattern.length <= 100`
- `1 <= queries.length <= 100`
- `1 <= queries[i].length <= 100`
- All strings consist of lowercase English letters.

## Related Problems

- Edit Distance (Levenshtein Distance)
- Delete Operation for Two Strings
- Minimum Number of Steps to Make Two Strings Anagram

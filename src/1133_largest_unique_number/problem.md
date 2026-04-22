# Largest Unique Number

**Difficulty:** Easy  
**Problem Number:** 1133

## Topics/Tags
- Hash Table
- Counting
- Array

## Problem Description

Given an integer array `nums`, return the largest integer that only occurs once. If no integer occurs once, return -1.

## Examples

### Example 1
**Input:**
```
nums = [5,7,3,9,4,9,8,3,1]
```
**Output:**
```
8
```
**Explanation:**
The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it's the answer.

### Example 2
**Input:**
```
nums = [9,9,8,8]
```
**Output:**
```
-1
```
**Explanation:**
There is no number that occurs only once.

### Example 3
**Input:**
```
nums = [1,1,1,1,2,2,2,3]
```
**Output:**
```
3
```
**Explanation:**
Only the number 3 occurs once in the array.

## Constraints

- `1 <= nums.length <= 2000`
- `0 <= nums[i] <= 10^9`
- All elements in the array are distinct or have duplicates.

## Related Problems

- First Unique Character in a String
- Contains Duplicate
- Majority Element

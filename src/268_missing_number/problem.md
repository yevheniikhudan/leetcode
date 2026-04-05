# 268. Missing Number

**Difficulty:** Easy

**Topics:** Array, Hash Table, Math, Bit Manipulation, Sorting

---

## Problem Description

Given an array `nums` containing `n` distinct numbers taken from the range `[0, n]`, return the only number in the range that is missing from the array.

---

## Examples

**Example 1:**
```
Input:  nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 
2 is the only number in the range that is missing from nums.
```

**Example 2:**
```
Input:  nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 
2 is the only number in the range that is missing from nums.
```

**Example 3:**
```
Input:  nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 
8 is the only number in the range that is missing from nums.
```

---

## Constraints

- `n == nums.length`
- `1 <= n <= 10^4`
- `0 <= nums[i] <= n`
- All the numbers of `nums` are **unique**.

---

## Follow-up

Could you implement a solution that runs in linear time using only constant extra space?

---

## Related Problems

- [41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/)
- [442. Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/)

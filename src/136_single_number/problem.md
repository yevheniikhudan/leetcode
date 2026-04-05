# 136. Single Number

Difficulty: Easy

## Problem

Given a non-empty array of integers `nums`, every element appears **twice** except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

## Examples

Example 1:
Input: [2, 2, 1]  
Output: 1

Example 2:
Input: [4, 1, 2, 1, 2]  
Output: 4

Example 3:
Input: [1]  
Output: 1

## Notes / Clarifications

- The array is guaranteed to contain exactly one element that appears only once while all other elements appear exactly twice.
- The order of elements in the input may be arbitrary.
- Negative integers are allowed.

## Constraints

- 1 <= nums.length <= 3 * 10^4
- -2^31 <= nums[i] <= 2^31 - 1
- Every element appears twice except for one element which appears once.

## Tags

Array, Bit Manipulation

## Common Approaches (brief)

- XOR scan (recommended): XORing all numbers together yields the single number because `a ^ a = 0` and `a ^ 0 = a`. Runs in O(n) time and O(1) extra space.
- Hash set / map: Count occurrences and find the element with count 1. Works but uses extra space (O(n)).
- Sorting: Sort and scan to find the unmatched element. Uses O(n log n) time and may modify input.

## Time / Space

- Optimal: Time O(n), Space O(1) using XOR.

## Related Problems

- 137. Single Number II (each element appears three times except one)
- 260. Single Number III (two elements appear once, others twice)
- 219. Contains Duplicate II
- 287. Find the Duplicate Number

## Example I/O Format (for local testing)

When writing local test scaffolding, print outputs in the project-required format:

```
actual | expected | PASS/FAIL
```

For example:

```
1 | 1 | PASS
4 | 4 | PASS
```

(End of file)
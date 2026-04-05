# Replace Elements with Greatest Element on Right Side

**Problem Number:** 1299  
**Difficulty:** Easy  
**Topics:** Array, Greedy

## Problem Description

Given an integer array `arr`, replace every element in that array with the greatest element among the elements to its right, and replace the last element with `-1`.

After doing so, return the array.

## Examples

**Example 1:**
```
Input: arr = [17, 18, 5, 4, 6, 1]
Output: [18, 6, 6, 6, 1, -1]
```

Explanation:
- Index 0: The greatest element to the right of `17` is `18`.
- Index 1: The greatest element to the right of `18` is `6`.
- Index 2: The greatest element to the right of `5` is `6`.
- Index 3: The greatest element to the right of `4` is `6`.
- Index 4: The greatest element to the right of `6` is `1`.
- Index 5: There are no elements to the right, so it becomes `-1`.

**Example 2:**
```
Input: arr = [400]
Output: [-1]
```

Explanation: There are no elements to the right of `400`.

**Example 3:**
```
Input: arr = [1, 2, 3, 4, 5]
Output: [5, 5, 5, 5, -1]
```

## Constraints

- `1 <= arr.length <= 10^4`
- `1 <= arr[i] <= 10^5`

## Related Problems

- [Find the Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) (Medium)
- [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) (Hard)
- [The Celebrity Problem](https://leetcode.com/problems/the-celebrity/) (Medium)

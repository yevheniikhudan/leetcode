# 4. Median of Two Sorted Arrays

**Difficulty:** Hard

## Problem Description

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return **the median** of the two sorted arrays.

The overall run time complexity should be **O(log (m+n))**.

## Examples

### Example 1:
```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```

### Example 2:
```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```

## Constraints

- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-10^6 <= nums1[i], nums2[i] <= 10^6`

## Topics

- Array
- Binary Search
- Divide and Conquer

## Key Observations

1. **Median Definition:**
   - For odd total length: middle element
   - For even total length: average of two middle elements

2. **Naive Solution:** O(m+n) - merge arrays then find median
   - But we need O(log(m+n)) → binary search!

3. **Key Insight:** Use binary search to partition both arrays such that:
   - Left partition has same number of elements as right partition (±1)
   - All elements in left ≤ all elements in right

4. **Binary Search on Smaller Array:**
   - Always perform binary search on the smaller array
   - This ensures optimal time complexity

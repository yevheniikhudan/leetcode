# 3075. Minimum Pair Removal to Sort Array I

[LeetCode link](https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/)

Given an array of integers `nums`, you can remove pairs of elements `(i, j)` (with `i < j`) such that `nums[i] > nums[j]`. After each removal, the remaining elements are concatenated in order. Return the minimum number of pairs you need to remove so that the array becomes non-decreasing.

- **Input:**
    - `nums` (List[int]): The input array.
- **Output:**
    - The minimum number of pairs to remove.

**Example 1:**

Input: nums = [3,2,1]
Output: 1
Explanation: Remove (0,2) or (0,1) or (1,2) to get a non-decreasing array.

**Example 2:**

Input: nums = [1,2,3,4]
Output: 0
Explanation: The array is already non-decreasing.

**Constraints:**
- 1 <= nums.length <= 100
- 1 <= nums[i] <= 100

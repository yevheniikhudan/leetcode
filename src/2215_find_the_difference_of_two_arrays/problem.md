# 2215. Find the Difference of Two Arrays

[LeetCode Link](https://leetcode.com/problems/find-the-difference-of-two-arrays/description/)

Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
- answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
- answer[1] is a list of all distinct integers in nums2 which are not present in nums1.

You may return the answer in any order.

**Example:**
Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]

**Constraints:**
- 1 <= nums1.length, nums2.length <= 1000
- -1000 <= nums1[i], nums2[i] <= 1000

# Problem 3741: Minimum Distance Between Three Equal Elements II

**Difficulty:** Medium

**Topics:** Array, Sliding Window, Hash Map

---

## Problem Description

Given an integer array `nums`, find the **minimum distance** between any **three equal elements** in the array.

The distance between three elements at indices `i`, `j`, and `k` (where `i < j < k`) is defined as `k - i` (the difference between the rightmost and leftmost indices).

If there are no three equal elements in the array, return `-1`.

---

## Examples

### Example 1:
- **Input:** `nums = [1,2,3,4,5,1]`
- **Output:** `-1`
- **Explanation:** There are only two 1's in the array, so no three equal elements exist.

### Example 2:
- **Input:** `nums = [1,1,1,1,1]`
- **Output:** `2`
- **Explanation:** The 1's are at indices [0, 1, 2, 3, 4]. Consider the 1's at indices 0, 1, and 2. The distance is 2 - 0 = 2. This is the minimum possible distance for any three 1's.

### Example 3:
- **Input:** `nums = [1,2,3]`
- **Output:** `-1`
- **Explanation:** No element appears three or more times in the array.

### Example 4:
- **Input:** `nums = [1,1,2,1,1]`
- **Output:** `2`
- **Explanation:** The 1's appear at indices [0, 1, 3, 4]. We can form triplets like (0, 1, 3) with distance 3 - 0 = 3, or (1, 3, 4) with distance 4 - 1 = 3. But the minimum distance is 2, which comes from indices with a span of 2.

### Example 5:
- **Input:** `nums = [10,10,10,10,10,10]`
- **Output:** `2`
- **Explanation:** Any three consecutive 10's have a distance of 2, which is the minimum possible.

---

## Constraints

- `1 <= nums.length <= 5 * 10^5`
- `1 <= nums[i] <= 100`

---

## Related Problems

- [Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/) - Finding duplicates within a specific distance
- [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/) - Sliding window technique
- [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/) - Finding all duplicate elements
- [Three Sum](https://leetcode.com/problems/3sum/) - Finding triplets in array
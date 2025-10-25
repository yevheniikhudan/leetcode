# 1. Two Sum

**Difficulty:** Easy  
**Topics:** Array, Hash Table  
**Source:** [LeetCode](https://leetcode.com/problems/two-sum/description/)

## Problem Description

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

You can return the answer in any order.

## Examples

### Example 1:
```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
```

### Example 2:
```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

### Example 3:
```
Input: nums = [3,3], target = 6
Output: [0,1]
```

## Constraints

- `2 <= nums.length <= 10^4`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= target <= 10^9`
- Only one valid answer exists.

## Follow-up

Can you come up with an algorithm that is less than `O(n^2)` time complexity?

## Hints

1. A really brute force way would be to search for all possible pairs of numbers but that would be too slow. Again, it's best to try out brute force solutions just for completeness. It is from these brute force solutions that you can come up with optimizations.

2. So, if we fix one of the numbers, say `x`, we have to scan the entire array to find the next number `y` which is `value - x` where value is the input parameter. Can we change our array somehow so that this search becomes faster?

3. The second train of thought is, without changing the array, can we use additional space somehow? Like maybe a hash map to speed up the search?

## Related Problems

- [3Sum](https://leetcode.com/problems/3sum/) (Medium)
- [4Sum](https://leetcode.com/problems/4sum/) (Medium)
- [Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) (Medium)
- [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) (Medium)
- [Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/) (Easy)
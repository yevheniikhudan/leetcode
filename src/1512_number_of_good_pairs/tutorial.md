# Tutorial: Number of Good Pairs

## Understanding the Problem
Given an array, count the number of pairs (i, j) such that nums[i] == nums[j] and i < j.

## Visual Example
- Input: [1,2,3,1,1,3]
- Output: 4 (pairs: (0,3), (0,4), (3,4), (2,5))

## Approaches
### 1. Hash Map Frequency Count (Most Efficient)
- Use a hash map to count occurrences of each number as you iterate.
- For each number, the number of good pairs it forms is equal to the current count of that number so far.
- Time: O(n), Space: O(n)

### 2. Brute Force
- Check all pairs (i, j) with i < j and count if nums[i] == nums[j].
- Time: O(n^2), Space: O(1)

## Complexity
- Hash map: O(n) time, O(n) space.
- Brute force: O(n^2) time, O(1) space.

## Edge Cases
- Empty array: 0 pairs.
- All elements unique: 0 pairs.
- All elements the same: maximum pairs.

## Optimization Notes
- The hash map approach is optimal for large arrays.

# Range Sum Query - Immutable - Tutorial

## Understanding the Problem
You need to answer multiple sum queries on a static array. Each query asks for the sum of a subarray from index `left` to `right` (inclusive).

## Approaches
### 1. Brute Force
- For each query, loop from `left` to `right` and sum the elements.
- Time: O(N) per query, O(1) extra space

### 2. Prefix Sum (Optimal)
- Precompute a prefix sum array: `prefix[i] = sum(nums[0..i-1])`
- For each query, answer in O(1): `sumRange(left, right) = prefix[right+1] - prefix[left]`
- Time: O(N) preprocessing, O(1) per query, O(N) space

## Time/Space Complexity
- Brute Force: O(N) per query, O(1) space
- Prefix Sum: O(N) preprocessing, O(1) per query, O(N) space

## Key Concepts
- Prefix sum
- Query optimization

## Edge Cases
- Single element queries
- Negative numbers

*No code in this tutorial section.*

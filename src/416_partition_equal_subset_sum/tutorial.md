# Tutorial: Partition Equal Subset Sum

## Understanding the Problem

This problem requires determining if an array can be divided into two subsets with equal sums. For this to be possible, the total sum of the array must be even, as each subset would need to sum to half the total.

## Visual Examples

Consider nums = [1,5,11,5]. Total sum = 22, half = 11.

Possible subsets: [1,5,5] sums to 11, [11] sums to 11.

For [1,2,3,5], sum=11, half=5.5, not integer, impossible.

## Approaches

### 1. Dynamic Programming (Most Efficient)

Use a boolean DP array where dp[i] indicates if sum i can be achieved.

Start with dp[0] = true.

For each number, update the DP array backwards to avoid using the same number twice.

Time: O(n * sum), Space: O(sum)

### 2. Recursion with Memoization

Recursive function to check if target sum can be achieved with remaining elements.

Memoize on index and current sum.

Time: O(n * sum), Space: O(n * sum)

### 3. Bitset Optimization

Use bitset to represent possible sums, shift and OR operations.

Time: O(n * sum / 64), Space: O(sum / 64)

## Time/Space Complexity Analysis

- DP: O(n * sum) time, O(sum) space
- Recursion: O(n * sum) time, O(n * sum) space
- Bitset: O(n * sum / 64) time, O(sum / 64) space

## Key Concepts and Patterns

- Subset Sum Problem variant
- DP for knapsack-like problems
- Sum must be even for possibility

## Edge Cases and Common Pitfalls

- Empty array: true (two empty subsets)
- Single element: false (can't split into two non-empty? Wait, problem allows empty subsets? Wait, no, subsets can be empty if sum 0, but constraints nums[i]>=1, so if sum even, possible.
- All zeros: but nums[i]>=1, no zeros.
- Large sum: up to 200*100=20000, ok.
- Pitfall: Forgetting to check if sum is odd.

## Optimization Notes

- If sum is odd, return false immediately.
- Use space-optimized DP if needed.

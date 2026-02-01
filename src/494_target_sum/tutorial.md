# Tutorial: Target Sum

## Understanding the Problem

The problem requires assigning either a '+' or '-' sign to each number in the array `nums` such that the resulting sum of the signed numbers equals the given `target`. This is equivalent to finding the number of ways to partition the array into two subsets where the difference between their sums is equal to the target.

Mathematically, if we let S be the total sum of all numbers, and P be the sum of the subset with '+' signs, then:
- P - (S - P) = target
- 2P = S + target
- P = (S + target) / 2

We need to count the number of subsets that sum to P, where P must be an integer (S + target must be even).

## Visual Examples

Consider nums = [1, 1, 1], target = 1.

Total sum S = 3.

P = (3 + 1) / 2 = 2.

Subsets summing to 2: {1,1} (the first two), ways: 3 (choose which one to exclude).

But with signs: +1 +1 -1, +1 -1 +1, -1 +1 +1. Yes, 3 ways.

For nums = [1,1,1,1,1], target=3, S=5, P=(5+3)/2=4.

Subsets summing to 4: choose 4 out of 5 ones, C(5,4)=5, yes.

## Approaches

### 1. Backtracking (Brute Force)
- Recursively try adding '+' or '-' to each number.
- Keep track of the current sum and index.
- When index == n, check if current sum == target.
- This explores all 2^n possibilities.

### 2. Dynamic Programming (Optimized)
- Use a DP array where dp[j] represents the number of ways to achieve sum j.
- Initialize dp[0] = 1.
- For each number, update the DP array by adding the number or subtracting (but since we transform to subset sum, we only add).
- Since we transformed to subset sum, we only need to count ways to reach P.

### 3. Memoized Backtracking
- Use recursion with memoization on (index, current_sum).
- Avoid recomputing subproblems.

## Time and Space Complexity

- Backtracking: O(2^n) time, O(n) space (recursion stack).
- DP: O(n * sum) time, O(sum) space.
- Memoized: O(n * sum) time, O(n * sum) space.

Since n <= 20 and sum <= 1000, all are feasible, but DP is preferred for clarity and efficiency.

## Key Concepts and Patterns

- Subset Sum Problem: Counting ways to achieve a target sum with subsets.
- Sign Assignment: Equivalent to choosing which numbers to subtract.
- DP Transition: For each number, update the DP table by considering adding it to existing sums.
- Memoization: Use a map or 2D array for (index, current_sum).

## Edge Cases and Common Pitfalls

- If S + target is odd or negative, impossible (0 ways).
- If target > S or target < -S, impossible.
- All numbers are 0: If target == 0, 2^n ways (all combinations), else 0.
- Single number: If nums[0] == target or -nums[0] == target, 1 way each.
- Target == 0: Count ways where positive and negative sums balance.
- Numbers can be 0: 0 doesn't change sum, but still counts as a choice.

## Optimization Notes

- Use DP for better performance when sum is large, but here n is small.
- In DP, use a 1D array and iterate backwards to avoid using the same number multiple times (but since each number is used once, forward is fine).
- For backtracking, prune if current_sum + remaining_max < target or current_sum - remaining_max > target, but since n=20, not necessary.

# House Robber II - Tutorial

## Understanding the Problem

House Robber II is a variation of the classic House Robber problem where houses are arranged in a **circle** instead of a straight line. This circular arrangement adds a critical constraint: you cannot rob both the first and the last house simultaneously, as they are adjacent in the circle.

The core challenge is maintaining the "no adjacent houses" rule while dealing with the circular topology. This transforms the problem into considering two separate linear robbery scenarios and selecting the optimal one.

## Key Insights

- **Circular Constraint**: The first and last houses cannot both be robbed
- **Subproblem Decomposition**: We can solve two linear House Robber problems:
  1. Rob houses from index 0 to n-2 (excluding the last house)
  2. Rob houses from index 1 to n-1 (excluding the first house)
- **Optimal Choice**: Take the maximum result from these two scenarios

## Approach 1: Dynamic Programming with Two Cases

### Strategy
1. Handle edge cases (n ≤ 2)
2. Compute maximum for range [0, n-2] using standard House Robber DP
3. Compute maximum for range [1, n-1] using standard House Robber DP
4. Return the maximum of the two results

### Time Complexity: O(n)
### Space Complexity: O(1)

### Visual Example
For nums = [2,3,2]:
- Case 1: Rob [2,3] → max(2, 3) = 3
- Case 2: Rob [3,2] → max(3, 2) = 3
- Result: max(3, 3) = 3

For nums = [1,2,3,1]:
- Case 1: Rob [1,2,3] → 1 + 3 = 4 (can't rob adjacent 2 and 3)
- Case 2: Rob [2,3,1] → 2 + 1 = 3
- Result: max(4, 3) = 4

## Edge Cases to Consider

- **Single House**: n=1 → rob the only house
- **Two Houses**: n=2 → rob the house with more money
- **All Zeros**: maximum is 0
- **All Same Values**: depends on positions due to circular constraint

## Common Pitfalls

- Forgetting the circular constraint and using standard House Robber directly
- Not handling n=1 and n=2 as special cases
- Incorrect range slicing for the two subproblems

## Optimization Notes

- The O(1) space solution uses only two variables to track previous maximums
- No need for full DP arrays since we only need the final maximum
- The two-case approach ensures we never violate the adjacency constraint

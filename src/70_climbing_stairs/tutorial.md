# Tutorial: Climbing Stairs

## Understanding the Problem
Staircase with n steps, climb 1 or 2 steps each time. Count distinct ways to reach top.

## Key Concepts
- **Fibonacci Sequence:** Ways(n) = Ways(n-1) + Ways(n-2)
- **Base Cases:** Ways(1) = 1, Ways(2) = 2

## Approaches

### 1. Recursion with Memoization
- Recur for n-1 and n-2, memoize results.
- Avoid recomputation.

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

### 2. Bottom-Up DP
- Array dp where dp[i] = ways to reach i.
- dp[1] = 1, dp[2] = 2, dp[i] = dp[i-1] + dp[i-2]

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

### 3. Optimized DP (Constant Space)
- Track last two values, update iteratively.

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

## Visual Example
n=3: 1+1+1, 1+2, 2+1 → 3 ways

## Edge Cases
- n=1: 1 way
- n=2: 2 ways
- n=45: Max, use int/long

## Common Pitfalls
- Overflow for large n (use long in Java/C++)
- Base cases: n=0 not needed, n starts at 1

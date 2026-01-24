# Tutorial: Min Cost Climbing Stairs

## Understanding the Problem
Staircase with costs, start from 0 or 1, climb 1 or 2 steps, find min cost to top.

## Key Concepts
- **DP State:** Min cost to reach each step.
- **Transition:** From i, can go to i+1 or i+2, add cost[i].
- **Base:** Top has cost 0.

## Approaches

### 1. Bottom-Up DP
- dp[i] = min cost to reach step i.
- dp[0] = cost[0], dp[1] = cost[1]
- dp[i] = cost[i] + min(dp[i-1], dp[i-2]) for i >= 2
- Answer: min(dp[n-1], dp[n-2])

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

### 2. Optimized DP (Constant Space)
- Track last two costs, update iteratively.

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

### 3. Recursion with Memoization
- Recur from 0 and 1, memoize min cost to top.

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

## Visual Example
cost = [10,15,20]

Start at 0: 10 + min(15,20) = 25  
Start at 1: 15 + 20 = 35  
Min: 25? Wait, example is 15, so start at 1, pay 15, jump to top.

Top is after last step.

## Edge Cases
- n=2: min(cost[0], cost[1])
- All costs same: any path
- Increasing costs: start at 0

## Common Pitfalls
- Top is beyond last step, no cost for top.
- Can start at 0 or 1, no initial cost.
- Min of last two dp values.

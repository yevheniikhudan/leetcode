# Tutorial: Coin Change

## Understanding the Problem
The Coin Change problem requires finding the minimum number of coins needed to make a specific amount using given coin denominations. You have unlimited coins of each type, and if it's impossible to make the amount, return -1.

This is a classic optimization problem where we need to minimize the count of coins while achieving the exact amount.

## Visual Examples
- **Example 1:** coins = [1,2,5], amount = 11
  - Possible combinations: 5+5+1 (3 coins), 2+2+2+2+2+1 (6 coins), etc.
  - Minimum is 3 coins.

- **Example 2:** coins = [2], amount = 3
  - Can't make odd amounts with even coins → impossible (-1)

- **Example 3:** coins = [1], amount = 0
  - No coins needed (0)

## Multiple Approaches

### 1. Dynamic Programming (Bottom-Up) - Most Efficient
Build a DP table where dp[i] represents the minimum coins needed for amount i.
- Initialize dp[0] = 0, others as infinity
- For each coin, update dp[j] for j from coin to amount
- Time: O(amount * coins.length), Space: O(amount)

### 2. Breadth-First Search (BFS)
Use a queue to explore combinations level by level (by coin count).
- Each state is (current amount, coins used)
- Use a visited set to avoid revisiting amounts
- Time: O(amount * coins.length), Space: O(amount)

### 3. Recursion with Memoization (Top-Down DP)
Recursive function that tries each coin, memoizing results.
- Base: if amount == 0, return 0; if amount < 0, return infinity
- For each coin, recurse on amount - coin
- Time: O(amount * coins.length), Space: O(amount)

## Time/Space Complexity Analysis
- **DP/BFS/Memoization:** O(amount * coins.length) time, O(amount) space
- DP is preferred for its simplicity and efficiency

## Key Concepts and Patterns
- **Unbounded Knapsack:** Similar to knapsack where items can be used multiple times
- **Minimum Count Problems:** Often solved with DP or BFS
- **Greedy Fails:** Greedy (largest coins first) doesn't work (e.g., coins=[1,3,4], amount=6 → greedy:4+1+1=3, optimal:3+3=2)

## Edge Cases and Common Pitfalls
- **Amount = 0:** Return 0 (no coins needed)
- **Impossible Amounts:** Return -1 (e.g., odd amount with even coins)
- **Large Coins:** If coin > amount, skip it
- **Duplicate Coins:** Handle by using sets or checking in DP
- **Overflow:** In code, use long for sums if needed, but constraints are safe

## Optimization Notes
- DP is fastest for coding interviews
- BFS can find minimum coins but may be slower in practice
- For very large amounts, consider if DP fits memory (10^4 is fine)
- If coins are sorted, can optimize DP loop order

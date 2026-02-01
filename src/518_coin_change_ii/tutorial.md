# Tutorial: Coin Change II

## Understanding the Problem

Count combinations (order doesn't matter) to make exact amount with infinite coins. Return 0 if impossible.

## Visual Examples

For amount=5, coins=[1,2,5]:

DP Table:

| Amount | 0 | 1 | 2 | 3 | 4 | 5 |
|--------|---|---|---|---|---|---|
| Initial | 1 | 0 | 0 | 0 | 0 | 0 |
| Coin 1  | 1 | 1 | 1 | 1 | 1 | 1 |
| Coin 2  | 1 | 1 | 2 | 2 | 3 | 3 |
| Coin 5  | 1 | 1 | 2 | 2 | 3 | 4 |

Ways: 4.

## Approaches

### 1. Dynamic Programming (Most Efficient)
- **Idea:** dp[i] = ways to make amount i.
- **Init:** dp[0] = 1
- **Transition:** For each coin, for j from coin to amount, dp[j] += dp[j - coin]
- **Time Complexity:** O(amount * len(coins))
- **Space Complexity:** O(amount)

### 2. Recursion with Memoization
- **Idea:** dfs(remaining, index) - ways from remaining with coins[index:]
- **Memo:** (remaining, index)
- **Time/Space:** O(amount * len(coins))

## Key Concepts and Patterns
- **Unbounded Knapsack:** For combinations, iterate coins outer, amounts inner.
- **Order Irrelevant:** Unlike permutations, combinations don't care about order.
- **Base Cases:** dp[0]=1, if remaining<0 or index==len, 0.

## Edge Cases and Common Pitfalls
- **amount=0:** 1 way (empty combination).
- **No coins, amount>0:** 0.
- **Coin > amount:** Skipped.
- **Pitfall:** Don't count permutations; use correct loop order.

## Optimization Notes
- DP is standard; recursion for small constraints.
- For large amount, DP is fine (5000*300).

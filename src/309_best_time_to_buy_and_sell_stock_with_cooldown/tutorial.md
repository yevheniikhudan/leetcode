# Tutorial: Best Time to Buy and Sell Stock with Cooldown

## Understanding the Problem

Maximize profit from stock prices with multiple buy/sell, but 1-day cooldown after sell. Can't buy on cooldown day, and can't hold multiple positions.

## Visual Examples

For prices = [1,2,3,0,2]:

States per day:
- Hold: Max profit if holding stock.
- Sold: Max profit after selling today.
- Cooldown: Max profit in cooldown (no action).

Transitions:
- From Hold: Sell (sold = hold + price) or hold.
- From Sold: Cooldown (cooldown = sold).
- From Cooldown: Buy (hold = cooldown - price) or cooldown.

Max at end: max(sold, cooldown).

## Approaches

### 1. Dynamic Programming (Most Efficient)
- **States:** hold[i], sold[i], cooldown[i] - max profit up to day i in each state.
- **Transitions:**
  - hold[i] = max(hold[i-1], cooldown[i-1] - prices[i])
  - sold[i] = hold[i-1] + prices[i]
  - cooldown[i] = max(cooldown[i-1], sold[i-1])
- **Base:** hold[0] = -prices[0], sold[0] = 0, cooldown[0] = 0
- **Time Complexity:** O(n)
- **Space Complexity:** O(n) or O(1) optimized

### 2. Optimized DP
- **Idea:** Use variables for previous states, update in place.
- **Time:** O(n)
- **Space:** O(1)

## Key Concepts and Patterns
- **State Machines:** For stock problems with constraints, define states (hold, sold, cooldown).
- **Transitions:** Based on actions (buy, sell, cooldown).
- **Optimization:** Reduce space by tracking only previous values.

## Edge Cases and Common Pitfalls
- **n=1:** 0 profit.
- **Decreasing Prices:** 0 profit.
- **Increasing Prices:** Buy low, sell high, with cooldown.
- **Pitfall:** Forgetting cooldown prevents buying next day after sell.

## Optimization Notes
- Use O(1) space for large n.
- DP handles all constraints elegantly.

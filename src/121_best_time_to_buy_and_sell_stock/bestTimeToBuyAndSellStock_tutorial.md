# Best Time to Buy and Sell Stock - Tutorial

## Problem Understanding

Find the maximum profit from buying and selling stock once, where you must buy before you sell.

**Key Constraints:**
- Can only make **one transaction** (buy once, sell once)
- Must **buy before selling** (can't sell then buy)
- Want to **maximize profit** (sell_price - buy_price)

**Key Insight**: We want to find the **maximum difference** between two numbers where the larger number comes after the smaller number.

## Approach: Single Pass with Min Tracking

### Strategy

Track the minimum price seen so far and calculate potential profit at each position:

1. Initialize `min_price` to infinity (or first element)
2. Initialize `max_profit` to 0
3. For each price:
   - Update `max_profit` if selling today gives better profit than before
   - Update `min_price` if today's price is lower than previous minimum
4. Return `max_profit`

### Why This Works

At each day, we have two choices:
1. **Sell today**: Calculate profit as `price[i] - min_price`
2. **Don't sell**: Keep looking for better opportunity

By tracking the minimum price seen so far, we always know the best buying price for any future selling day.

### Algorithm Steps

1. Set min_price = infinity (or very large number)
2. Set max_profit = 0
3. For each price in prices:
   - If price < min_price: update min_price = price
   - Calculate potential profit = price - min_price
   - If potential profit > max_profit: update max_profit
4. Return max_profit

### Example Walkthrough

```
prices = [7, 1, 5, 3, 6, 4]

Day 0 (price=7):
  min_price = 7
  profit = 7 - 7 = 0
  max_profit = 0

Day 1 (price=1):
  min_price = 1 (updated)
  profit = 1 - 1 = 0
  max_profit = 0

Day 2 (price=5):
  min_price = 1
  profit = 5 - 1 = 4
  max_profit = 4 (updated)

Day 3 (price=3):
  min_price = 1
  profit = 3 - 1 = 2
  max_profit = 4

Day 4 (price=6):
  min_price = 1
  profit = 6 - 1 = 5
  max_profit = 5 (updated)

Day 5 (price=4):
  min_price = 1
  profit = 4 - 1 = 3
  max_profit = 5

Result: max_profit = 5
(Buy at 1, sell at 6)
```

### Time & Space Complexity

- **Time**: O(n) - Single pass through the array
- **Space**: O(1) - Only using two variables

## Alternative Approach: Kadane's Algorithm Variant

This problem is similar to **Maximum Subarray** problem. We can think of it as finding the maximum sum of consecutive differences.

**Transform the problem:**
- Instead of looking at prices, look at daily changes: `[prices[i] - prices[i-1]]`
- Find maximum sum of consecutive changes
- This gives us the maximum profit

However, the **min tracking approach is simpler** and more intuitive for this problem.

## Key Insights

1. **Greedy approach works**: Always buy at the lowest price seen so far
2. **One pass sufficient**: Don't need to check all pairs
3. **Order matters**: Must buy before sell (can't look backward)
4. **Always profitable to track min**: Even if we don't sell today, knowing the min helps future decisions

## Common Mistakes

1. **Trying to sell before buying**: Make sure min_price is updated before calculating profit
2. **Using nested loops**: O(n²) is too slow, use single pass
3. **Forgetting edge case**: If prices only decrease, profit should be 0
4. **Not initializing properly**: min_price should start at infinity or first price

## Edge Cases

1. **Single day** (length 1): Can't sell, return 0
2. **Prices always decreasing**: No profit possible, return 0
3. **Prices always increasing**: Buy first day, sell last day
4. **All same price**: No profit, return 0
5. **Best buy day is last day**: Can't sell, profit = 0

## Comparison with Other Stock Problems

| Problem | Transactions | Difficulty | Approach |
|---------|-------------|------------|----------|
| Stock I (this) | 1 | Easy | Track min price |
| Stock II | Unlimited | Medium | Sum all gains |
| Stock III | 2 | Hard | Dynamic Programming |
| Stock IV | k | Hard | DP with states |

## Visual Example

```
prices = [7, 1, 5, 3, 6, 4]

Price chart:
7 ●
6 |           ●
5 |     ●     |
4 |     |     |   ●
3 |     |   ● |   |
2 |     |     |   |
1 |   ● |     |   |
  0   1   2   3   4   5  (days)

Best strategy:
- Buy at day 1 (price=1) ●
- Sell at day 4 (price=6) ●
- Profit = 6 - 1 = 5
```

## Related Concepts

- **Greedy Algorithm**: Making locally optimal choices (always buy at minimum)
- **Kadane's Algorithm**: Maximum subarray sum (alternative view)
- **Dynamic Programming**: Can be viewed as DP with two states (bought/not bought)
- **Sliding Window**: Similar pattern of tracking minimum in a window

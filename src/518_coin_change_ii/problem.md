# 518. Coin Change II

**Difficulty:** Medium

**Topics:** Array, Dynamic Programming

## Problem Description

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return `0`.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

## Examples

### Example 1

**Input:** amount = 5, coins = [1,2,5]  
**Output:** 4  
**Explanation:** there are four ways to make up the amount:  
5=5  
5=2+2+1  
5=2+1+1+1  
5=1+1+1+1+1

### Example 2

**Input:** amount = 3, coins = [2]  
**Output:** 0  
**Explanation:** the amount of 3 cannot be made up just with coins of 2.

### Example 3

**Input:** amount = 10, coins = [10]  
**Output:** 1

## Constraints

- `1 <= coins.length <= 300`
- `1 <= coins[i] <= 5000`
- All the values of `coins` are unique.
- `0 <= amount <= 5000`

## Related Problems

- [Coin Change](https://leetcode.com/problems/coin-change/) - Medium
- [Maximum Value of K Coins From Piles](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/) - Hard
- [Number of Ways to Earn Points](https://leetcode.com/problems/number-of-ways-to-earn-points/) - Hard
- [Count of Sub-Multisets With Bounded Sum](https://leetcode.com/problems/count-of-sub-multisets-with-bounded-sum/) - Hard
- [Length of the Longest Subsequence That Sums to Target](https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/) - Medium
- [The Number of Ways to Make the Sum](https://leetcode.com/problems/the-number-of-ways-to-make-the-sum/) - Medium
- [Inverse Coin Change](https://leetcode.com/problems/inverse-coin-change/) - Medium

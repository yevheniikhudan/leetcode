from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float("inf")] * (amount + 1)
        dp[0] = 0

        for coin in coins:
            for a in range(1, len(dp)):
                remainder = a - coin
                if remainder >= 0:
                    dp[a] = min(dp[a], 1 + dp[remainder])

        return -1 if dp[amount] == float("inf") else dp[amount]

    def coinChangeTopDown(self, coins: List[int], amount: int) -> int:
        memo = {}

        def dfs(amount):
            if amount in memo:
                return memo[amount]

            if amount == 0:
                return 0

            res = float("inf")

            for coin in coins:
                remainder = amount - coin
                if remainder >= 0:
                    res = min(res, 1 + dfs(remainder))

            memo[amount] = res

            return memo[amount]

        res = dfs(amount)
        return -1 if res == float("inf") else res


# Test helper
def test_coin_change():
    solution = Solution()

    # Test case 1: Example 1
    coins1 = [1, 2, 5]
    amount1 = 11
    expected1 = 3
    actual1 = solution.coinChange(coins1, amount1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    coins2 = [2]
    amount2 = 3
    expected2 = -1
    actual2 = solution.coinChange(coins2, amount2)
    print(f"{actual2} | {expected2}")

    # Test case 3: Example 3
    coins3 = [1]
    amount3 = 0
    expected3 = 0
    actual3 = solution.coinChange(coins3, amount3)
    print(f"{actual3} | {expected3}")

    # Test case 4: Possible with multiple coins
    coins4 = [1, 3, 4]
    amount4 = 6
    expected4 = 2  # 3 + 3
    actual4 = solution.coinChange(coins4, amount4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Impossible
    coins5 = [5]
    amount5 = 3
    expected5 = -1
    actual5 = solution.coinChange(coins5, amount5)
    print(f"{actual5} | {expected5}")

    # Test case 6: Large amount
    coins6 = [1, 2, 5]
    amount6 = 100
    expected6 = 20  # 20 fives
    actual6 = solution.coinChange(coins6, amount6)
    print(f"{actual6} | {expected6}")


if __name__ == "__main__":
    test_coin_change()

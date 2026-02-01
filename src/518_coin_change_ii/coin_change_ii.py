from typing import List


class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1

        for coin in coins:
            for j in range(coin, amount + 1):
                dp[j] += dp[j - coin]

        return dp[amount]

    def changeTopDown(self, amount: int, coins: List[int]) -> int:
        n = len(coins)
        memo = {}

        def dfs(i: int, total: int) -> int:
            if (i, total) in memo:
                return memo[(i, total)]
            if i == n or total > amount:
                return 0
            if total == amount:
                return 1

            res = 0
            res += dfs(i + 1, total)
            res += dfs(i, total + coins[i])

            memo[(i, total)] = res
            return res

        return dfs(0, 0)


# Helper functions for testing


def test_case(amount, coins, expected):
    sol = Solution()
    actual = sol.change(amount, coins)
    print(f"{actual} | {expected}")


# Test cases

if __name__ == "__main__":
    test_case(5, [1, 2, 5], 4)
    test_case(3, [2], 0)
    test_case(10, [10], 1)
    test_case(0, [1], 1)
    test_case(1, [], 0)
    test_case(2, [1, 2], 2)

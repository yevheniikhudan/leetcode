from typing import List


class Solution:
    def maxProfitTopDown(self, prices: List[int]) -> int:
        hold = float("-inf")
        sold = 0
        colldown = 0

        for price in prices:
            prev_sold = sold

            sold = hold + price  # sell today
            hold = max(hold, colldown - price)  # buy or keep holding
            colldown = max(colldown, prev_sold)  # cooldown or stay resting

        return max(sold, colldown)

    def maxProfitTopDownTopDown(self, prices: List[int]) -> int:
        memo = {}

        def dfs(i, buy):
            if (i, buy) in memo:
                return memo[(i, buy)]
            if i >= len(prices):
                return 0

            cooldown = dfs(i + 1, buy)
            res = 0
            if buy:
                res = max(dfs(i + 1, False) - prices[i], cooldown)
            else:
                res = max(dfs(i + 2, True) + prices[i], cooldown)

            memo[(i, buy)] = res
            return res

        return dfs(0, True)


# Helper functions for testing


def test_case(prices, expected):
    sol = Solution()
    actual = sol.maxProfit(prices)
    print(f"{actual} | {expected}")


# Test cases

if __name__ == "__main__":
    test_case([1, 2, 3, 0, 2], 3)
    test_case([1], 0)
    test_case([1, 2], 1)
    test_case([2, 1], 0)
    test_case([1, 2, 4], 3)
    test_case([1, 3, 2, 4], 4)

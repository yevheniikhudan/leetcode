"""
121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock
on the ith day. You want to maximize your profit by choosing a single day to
buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot
achieve any profit, return 0.
"""

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        min_price = float('inf')
        
        for price in prices:
            min_price = min(min_price, price)
            res = max(res, price - min_price)
        
        return res


def test_best_time_to_buy_and_sell_stock():
    solution = Solution()

    # Test case 1: Example 1
    prices = [7, 1, 5, 3, 6, 4]
    result = solution.maxProfit(prices)
    expected = 5
    print(f"Test 1: {result} (expected: {expected})")

    # Test case 2: Example 2 - prices decreasing
    prices = [7, 6, 4, 3, 1]
    result = solution.maxProfit(prices)
    expected = 0
    print(f"Test 2: {result} (expected: {expected})")

    # Test case 3: Single element
    prices = [5]
    result = solution.maxProfit(prices)
    expected = 0
    print(f"Test 3: {result} (expected: {expected})")

    # Test case 4: Prices increasing
    prices = [1, 2, 3, 4, 5]
    result = solution.maxProfit(prices)
    expected = 4  # Buy at 1, sell at 5
    print(f"Test 4: {result} (expected: {expected})")

    # Test case 5: All same price
    prices = [3, 3, 3, 3]
    result = solution.maxProfit(prices)
    expected = 0
    print(f"Test 5: {result} (expected: {expected})")

    # Test case 6: Two elements
    prices = [2, 4]
    result = solution.maxProfit(prices)
    expected = 2
    print(f"Test 6: {result} (expected: {expected})")

    # Test case 7: Buy at end
    prices = [3, 2, 6, 5, 0, 3]
    result = solution.maxProfit(prices)
    expected = 4  # Buy at 2, sell at 6
    print(f"Test 7: {result} (expected: {expected})")

    # Test case 8: Large dataset simulation
    prices = [2, 1, 4, 5, 2, 9, 7]
    result = solution.maxProfit(prices)
    expected = 8  # Buy at 1, sell at 9
    print(f"Test 8: {result} (expected: {expected})")


if __name__ == "__main__":
    test_best_time_to_buy_and_sell_stock()

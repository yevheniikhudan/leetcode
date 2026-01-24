from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        a, b = cost[0], cost[1]

        for i in range(2, len(cost)):
            a, b = b, cost[i] + min(a, b)

        return min(a, b)


# Test helper
def test_min_cost_climbing_stairs():
    solution = Solution()

    # Test case 1: Example 1
    cost1 = [10, 15, 20]
    expected1 = 15
    actual1 = solution.minCostClimbingStairs(cost1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    cost2 = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    expected2 = 6
    actual2 = solution.minCostClimbingStairs(cost2)
    print(f"{actual2} | {expected2}")

    # Test case 3: n=2
    cost3 = [1, 2]
    expected3 = 1
    actual3 = solution.minCostClimbingStairs(cost3)
    print(f"{actual3} | {expected3}")

    # Test case 4: Equal costs
    cost4 = [5, 5, 5]
    expected4 = 5
    actual4 = solution.minCostClimbingStairs(cost4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Increasing
    cost5 = [1, 2, 3, 4]
    expected5 = 4
    actual5 = solution.minCostClimbingStairs(cost5)
    print(f"{actual5} | {expected5}")


if __name__ == "__main__":
    test_min_cost_climbing_stairs()

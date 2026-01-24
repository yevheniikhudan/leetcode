from collections import deque
from typing import List


class Solution:
    def findCheapestPrice(
        self, n: int, flights: List[List[int]], src: int, dst: int, k: int
    ) -> int:
        prices = [float("inf")] * n
        prices[src] = 0
        adjList = [[] for _ in range(n)]
        for u, v, cst in flights:
            adjList[u].append([v, cst])

        q = deque([(0, src, 0)])

        while q:
            cst, node, stops = q.popleft()
            if stops > k:
                continue

            for adj, adjCost in adjList[node]:
                newCost = cst + adjCost
                if newCost < prices[adj]:
                    prices[adj] = newCost
                    q.append((newCost, adj, stops + 1))

        return prices[dst] if prices[dst] != float("inf") else -1


# Test helper
def test_find_cheapest_price():
    solution = Solution()

    # Test case 1: Example 1
    n1 = 4
    flights1 = [[0, 1, 100], [1, 2, 100], [2, 0, 100], [1, 3, 600], [2, 3, 200]]
    src1, dst1, k1 = 0, 3, 1
    expected1 = 700
    actual1 = solution.findCheapestPrice(n1, flights1, src1, dst1, k1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    n2 = 3
    flights2 = [[0, 1, 100], [1, 2, 100], [0, 2, 500]]
    src2, dst2, k2 = 0, 2, 1
    expected2 = 200
    actual2 = solution.findCheapestPrice(n2, flights2, src2, dst2, k2)
    print(f"{actual2} | {expected2}")

    # Test case 3: Example 3
    n3 = 3
    flights3 = [[0, 1, 100], [1, 2, 100], [0, 2, 500]]
    src3, dst3, k3 = 0, 2, 0
    expected3 = 500
    actual3 = solution.findCheapestPrice(n3, flights3, src3, dst3, k3)
    print(f"{actual3} | {expected3}")

    # Test case 4: No path
    n4 = 3
    flights4 = [[0, 1, 100], [1, 2, 100]]
    src4, dst4, k4 = 0, 2, 0
    expected4 = -1
    actual4 = solution.findCheapestPrice(n4, flights4, src4, dst4, k4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Direct flight cheaper
    n5 = 2
    flights5 = [[0, 1, 50], [0, 1, 100]]
    src5, dst5, k5 = 0, 1, 1
    expected5 = 50
    actual5 = solution.findCheapestPrice(n5, flights5, src5, dst5, k5)
    print(f"{actual5} | {expected5}")


if __name__ == "__main__":
    test_find_cheapest_price()

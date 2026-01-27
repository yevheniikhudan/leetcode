from typing import List
import heapq


class Solution:
    def minimumCostPath(self, n: int, edges: List[List[int]]) -> int:
        adjList = [[] for _ in range(n)]

        for u, v, w in edges:
            adjList[u].append([v, w])
            adjList[v].append([u, 2 * w])

        shortest = [-1] * n
        h = [(0, 0)]

        while h:
            weight, u = heapq.heappop(h)

            if shortest[u] != -1:
                continue

            shortest[u] = weight

            if u == n - 1:
                return weight

            for adj, adjWeight in adjList[u]:
                if shortest[adj] != -1:
                    continue

                heapq.heappush(h, (adjWeight + weight, adj))

        return shortest[n - 1]


# Test helper
def test_minimum_cost_path():
    solution = Solution()

    # Test case 1: Example 1
    n1 = 4
    edges1 = [[0, 1, 3], [3, 1, 1], [2, 3, 4], [0, 2, 2]]
    expected1 = 5
    actual1 = solution.minimumCostPath(n1, edges1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    n2 = 4
    edges2 = [[0, 2, 1], [2, 1, 1], [1, 3, 1], [2, 3, 3]]
    expected2 = 3
    actual2 = solution.minimumCostPath(n2, edges2)
    print(f"{actual2} | {expected2}")

    # Test case 3: No path
    n3 = 3
    edges3 = [[0, 1, 1], [1, 2, 1]]
    expected3 = 2  # Direct path 0->1->2
    actual3 = solution.minimumCostPath(n3, edges3)
    print(f"{actual3} | {expected3}")

    # Test case 4: Direct path
    n4 = 2
    edges4 = [[0, 1, 5]]
    expected4 = 5
    actual4 = solution.minimumCostPath(n4, edges4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Reversal needed
    n5 = 3
    edges5 = [[1, 0, 1], [1, 2, 1]]
    expected5 = 3
    actual5 = solution.minimumCostPath(n5, edges5)
    print(f"{actual5} | {expected5}")

    # Test case 6: Impossible
    n6 = 3
    edges6 = [[0, 1, 1]]
    expected6 = -1
    actual6 = solution.minimumCostPath(n6, edges6)
    print(f"{actual6} | {expected6}")


if __name__ == "__main__":
    test_minimum_cost_path()

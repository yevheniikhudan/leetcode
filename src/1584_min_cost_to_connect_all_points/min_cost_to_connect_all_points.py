from typing import List


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n, node = len(points), 0
        if n == 1:
            return 0

        dist = [float("inf")] * n
        visit = [False] * n
        numEdges, res = 0, 0

        while numEdges < n - 1:
            visit[node] = True
            nextNode = -1
            for i in range(n):
                if visit[i]:
                    continue
                curDist = abs(points[i][0] - points[node][0]) + abs(
                    points[i][1] - points[node][1]
                )
                dist[i] = min(dist[i], curDist)
                if nextNode == -1 or dist[i] < dist[nextNode]:
                    nextNode = i

            res += dist[nextNode]
            node = nextNode
            numEdges += 1

        return res


# Test helper
def test_min_cost_connect_points():
    solution = Solution()

    # Test case 1: Example 1
    points1 = [[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]
    expected1 = 20
    actual1 = solution.minCostConnectPoints(points1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    points2 = [[3, 12], [-2, 5], [-4, 1]]
    expected2 = 18
    actual2 = solution.minCostConnectPoints(points2)
    print(f"{actual2} | {expected2}")

    # Test case 3: Two points
    points3 = [[0, 0], [1, 1]]
    expected3 = 2
    actual3 = solution.minCostConnectPoints(points3)
    print(f"{actual3} | {expected3}")

    # Test case 4: One point
    points4 = [[0, 0]]
    expected4 = 0
    actual4 = solution.minCostConnectPoints(points4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Three points in line
    points5 = [[0, 0], [1, 0], [2, 0]]
    expected5 = 2
    actual5 = solution.minCostConnectPoints(points5)
    print(f"{actual5} | {expected5}")


if __name__ == "__main__":
    test_min_cost_connect_points()

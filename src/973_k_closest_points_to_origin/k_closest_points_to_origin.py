import heapq
from typing import List


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        h = []

        for point in points:
            dist = -(point[0] ** 2 + point[1] ** 2)
            heapq.heappush(h, (dist, point[0], point[1]))
            if len(h) > k:
                heapq.heappop(h)

        res = []

        for _, x, y in h:
            res.append([x, y])

        return res


# Test scaffolding
if __name__ == "__main__":
    tests = [
        ([[[1, 3], [-2, 2]], 1], [[-2, 2]]),
        ([[[3, 3], [5, -1], [-2, 4]], 2], [[3, 3], [-2, 4]]),
        ([[[0, 1], [1, 0]], 2], [[0, 1], [1, 0]]),
        ([[[2, 2], [2, 2], [2, 2]], 2], [[2, 2], [2, 2]]),
        ([[[1, 2], [2, 1], [0, 0]], 1], [[0, 0]]),
    ]
    sol = Solution()
    for (points, k), expected in tests:
        actual = sol.kClosest(points, k)
        print(f"{actual} | {expected}")

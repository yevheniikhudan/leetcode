import heapq
from typing import List
import collections


class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        # Dijkstra's Algorithm
        n = len(grid)
        visit = set()
        h = [[grid[0][0], 0, 0]]
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        visit.add((0, 0))

        while h:
            time, row, col = heapq.heappop(h)
            if row == n - 1 and col == n - 1:
                return time

            for dR, dC in directions:
                newRow, newCol = row + dR, col + dC
                if (
                    0 <= newRow < n
                    and 0 <= newCol < n
                    and (newRow, newCol) not in visit
                ):
                    visit.add((newRow, newCol))
                    heapq.heappush(h, [max(time, grid[newRow][newCol]), newRow, newCol])


# Test helper
def test_swim_in_water():
    solution = Solution()

    # Test case 1: Example 1
    grid1 = [[0, 2], [1, 3]]
    expected1 = 3
    actual1 = solution.swimInWater(grid1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    grid2 = [
        [0, 1, 2, 3, 4],
        [24, 23, 22, 21, 5],
        [12, 13, 14, 15, 16],
        [11, 17, 18, 19, 20],
        [10, 9, 8, 7, 6],
    ]
    expected2 = 16
    actual2 = solution.swimInWater(grid2)
    print(f"{actual2} | {expected2}")

    # Test case 3: n=1
    grid3 = [[5]]
    expected3 = 5
    actual3 = solution.swimInWater(grid3)
    print(f"{actual3} | {expected3}")

    # Test case 4: 2x2 simple
    grid4 = [[0, 1], [2, 3]]
    expected4 = 3
    actual4 = solution.swimInWater(grid4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Already connected
    grid5 = [[0, 0], [0, 0]]
    expected5 = 0
    actual5 = solution.swimInWater(grid5)
    print(f"{actual5} | {expected5}")


if __name__ == "__main__":
    test_swim_in_water()

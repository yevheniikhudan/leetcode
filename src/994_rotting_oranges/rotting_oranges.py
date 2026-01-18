from collections import deque
from typing import List


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        q = deque()
        time = 0
        fresh = 0
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 2:
                    q.append((row, col))
                if grid[row][col] == 1:
                    fresh += 1

        while q and fresh > 0:
            for _ in range(len(q)):
                row, col = q.popleft()

                for dR, dC in directions:
                    newRow = row + dR
                    newCol = col + dC

                    if (
                        0 <= newRow < rows
                        and 0 <= newCol < cols
                        and grid[newRow][newCol] == 1
                    ):
                        q.append((newRow, newCol))
                        grid[newRow][newCol] = 2
                        fresh -= 1

            time += 1

        return -1 if fresh > 0 else time


# Test scaffolding
if __name__ == "__main__":
    grid = [[2, 1, 1], [1, 1, 0], [0, 1, 1]]
    print(Solution().orangesRotting(grid))  # 4

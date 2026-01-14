from typing import List


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        res = 0
        rows = len(grid)
        cols = len(grid[0])
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        def dfs(row, col):
            nonlocal res

            if row < 0 or row >= rows or col < 0 or col >= cols or grid[row][col] == 0:
                return 0

            grid[row][col] = 0
            area = 1

            for dr, dc in directions:
                area += dfs(row + dr, col + dc)

            res = max(res, area)

            return area

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == 1:
                    dfs(row, col)

        return res


# Test scaffolding
if __name__ == "__main__":
    grid = [
        [0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
        [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
    ]
    print(Solution().maxAreaOfIsland(grid))  # 6

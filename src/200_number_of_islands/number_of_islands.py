from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        res = 0
        rows = len(grid)
        cols = len(grid[0])
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]

        def dfs(row: int, col: int) -> None:
            if (
                row < 0
                or row >= rows
                or col < 0
                or col >= cols
                or grid[row][col] == "0"
            ):
                return

            grid[row][col] = "0"

            for dr, dc in directions:
                dfs(row + dr, col + dc)

        for row in range(rows):
            for col in range(cols):
                if grid[row][col] == "1":
                    res += 1
                    dfs(row, col)

        return res


# Test scaffolding
if __name__ == "__main__":
    grid = [
        ["1", "1", "1", "1", "0"],
        ["1", "1", "0", "1", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "0", "0", "0"],
    ]
    print(Solution().numIslands(grid))  # 1

from typing import List


class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        m = len(matrix[0])
        dirs = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        lis = 0
        memo = {}

        def dfs(row, col, prevValue):
            if (
                row < 0
                or row >= n
                or col < 0
                or col >= m
                or matrix[row][col] <= prevValue
            ):
                return 0

            if (row, col) in memo:
                return memo[(row, col)]

            res = 1
            for dR, dC in dirs:
                res = max(res, 1 + dfs(row + dR, col + dC, matrix[row][col]))
            memo[(row, col)] = res
            return res

        for row in range(n):
            for col in range(m):
                lis = max(lis, dfs(row, col, -1))

        return lis


def test_longestIncreasingPath():
    sol = Solution()
    # Test case 1: Example 1
    print(f"{sol.longestIncreasingPath([[9,9,4],[6,6,8],[2,1,1]])} | 4")
    # Test case 2: Example 2
    print(f"{sol.longestIncreasingPath([[3,4,5],[3,2,6],[2,2,1]])} | 4")
    # Test case 3: Example 3
    print(f"{sol.longestIncreasingPath([[1]])} | 1")
    # Test case 4: All equal
    print(f"{sol.longestIncreasingPath([[1,1],[1,1]])} | 1")
    # Test case 5: Increasing row
    print(f"{sol.longestIncreasingPath([[1,2,3]])} | 3")
    # Test case 6: Empty? But constraints m>=1
    print(f"{sol.longestIncreasingPath([[2147483647,1]])} | 2")
    # Test case 7: Empty? But constraints m>=1


if __name__ == "__main__":
    test_longestIncreasingPath()

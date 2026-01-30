from typing import List


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [0] * (n + 1)
        dp[1] = 1

        for _ in range(m):
            for col in range(1, n + 1):
                dp[col] = dp[col] + dp[col - 1]

        return dp[n]

    def uniquePathsTopDown(self, m: int, n: int) -> int:
        memo = {}

        def dfs(row, col):
            if (row, col) in memo:
                return memo[(row, col)]

            if row == m - 1 and col == n - 1:
                return 1

            if row >= m or col >= n:
                return 0

            memo[(row, col)] = dfs(row + 1, col) + dfs(row, col + 1)
            return memo[(row, col)]

        return dfs(0, 0)


# Helper functions for testing


def test_case(m, n, expected):
    sol = Solution()
    actual = sol.uniquePaths(m, n)
    print(f"{actual} | {expected}")


# Test cases

if __name__ == "__main__":
    test_case(3, 7, 28)
    test_case(3, 2, 3)
    test_case(1, 1, 1)
    test_case(1, 10, 1)
    test_case(10, 1, 1)
    test_case(2, 2, 2)

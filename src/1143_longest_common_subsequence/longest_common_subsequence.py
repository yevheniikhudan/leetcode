from typing import List


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # swap to reduce space to O(min(len(text1), len(text2)))
        if len(text1) < len(text2):
            text1, text2 = text2, text1
        dp = [0] * (len(text2) + 1)

        for i in range(len(text1)):
            next_dp = [0] * (len(text2) + 1)
            for j in range(len(text2)):
                if text1[i] == text2[j]:
                    next_dp[j + 1] = 1 + dp[j]
                else:
                    next_dp[j + 1] = max(next_dp[j], dp[j + 1])

            dp = next_dp

        return dp[len(text2)]

    def longestCommonSubsequence2DP(self, text1: str, text2: str) -> int:
        dp = [[0 for _ in range(len(text2) + 1)] for _ in range(len(text1) + 1)]

        for i in range(len(text1)):
            for j in range(len(text2)):
                if text1[i] == text2[j]:
                    dp[i + 1][j + 1] = 1 + dp[i][j]
                else:
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1])

        return dp[len(text1)][len(text2)]

    def longestCommonSubsequenceTopDown(self, text1: str, text2: str) -> int:
        memo = {}

        def dfs(i1, i2):
            if (i1, i2) in memo:
                return memo[(i1, i2)]
            if i1 == len(text1) or i2 == len(text2):
                return 0

            res = 0
            if text1[i1] == text2[i2]:
                res = 1 + dfs(i1 + 1, i2 + 1)
            else:
                res = max(dfs(i1 + 1, i2), dfs(i1, i2 + 1))

            memo[(i1, i2)] = res
            return res

        return dfs(0, 0)


# Helper functions for testing


def test_case(text1, text2, expected):
    sol = Solution()
    actual = sol.longestCommonSubsequence(text1, text2)
    print(f"{actual} | {expected}")


# Test cases

if __name__ == "__main__":
    test_case("abcde", "ace", 3)
    test_case("abc", "abc", 3)
    test_case("abc", "def", 0)
    test_case("", "a", 0)
    test_case("a", "a", 1)
    test_case("abcd", "acbd", 3)

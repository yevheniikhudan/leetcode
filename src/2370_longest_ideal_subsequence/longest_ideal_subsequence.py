from typing import List


class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        dp = [0] * 26
        for char in s:
            curr = ord(char) - ord("a")
            max_len = 0
            for prev in range(26):
                if abs(curr - prev) <= k:
                    max_len = max(max_len, dp[prev])
            dp[curr] = max_len + 1
        return max(dp)


# Test scaffolding
def test():
    sol = Solution()
    print(sol.longestIdealString("acfgbd", 2), "| 4")
    print(sol.longestIdealString("abcd", 3), "| 4")
    print(sol.longestIdealString("abcde", 0), "| 1")
    print(sol.longestIdealString("a", 25), "| 1")
    print(sol.longestIdealString("azazaz", 25), "| 6")


if __name__ == "__main__":
    test()

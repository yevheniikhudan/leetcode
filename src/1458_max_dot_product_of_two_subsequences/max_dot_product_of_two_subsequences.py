from typing import List


class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        dp = [[0] * m for _ in range(n)]
        res = float("-inf")

        for i in range(n):
            for j in range(m):
                val = nums1[i] * nums2[j]
                dp[i][j] = val

                if i > 0 and j > 0:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1])

                if i > 0:
                    dp[i][j] = max(dp[i][j], dp[i - 1][j])

                if j > 0:
                    dp[i][j] = max(dp[i][j], dp[i][j - 1])

                res = max(res, dp[i][j])

        return res


# Test scaffolding
if __name__ == "__main__":
    sol = Solution()
    tests = [
        ([2, 1, -2, 5], [3, 0, -6], 18),
        ([3, -2], [2, -6, 7], 21),
        ([-1, -1], [1, 1], -1),
        ([1], [1], 1),
        ([-5], [-2], 10),
        ([1, 2, 3], [-1, -2, -3], -1),
    ]
    for i, (nums1, nums2, expected) in enumerate(tests, 1):
        result = sol.maxDotProduct(nums1, nums2)
        print(f"Test {i}: {result} | {expected}")

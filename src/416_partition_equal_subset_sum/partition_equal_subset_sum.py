from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        numsTotal = sum(nums)
        if numsTotal % 2:
            return False
        targetSum = numsTotal // 2
        dp = [False] * (targetSum + 1)
        dp[0] = True

        for num in nums:
            # Update DP for each number, move backwards to reuse the same number
            for j in range(targetSum, num - 1, -1):
                dp[j] = dp[j] or dp[j - num]

        return dp[targetSum]


# Helper functions for testing


def test_case(nums, expected):
    sol = Solution()
    actual = sol.canPartition(nums)
    print(f"{actual} | {expected}")


# Test cases

if __name__ == "__main__":
    test_case([1, 5, 11, 5], True)
    test_case([1, 2, 3, 5], False)
    test_case([1, 1], True)
    test_case([1], False)
    test_case([0, 0], True)
    test_case([2, 2, 2, 2], True)

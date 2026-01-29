from bisect import bisect_left
from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = []
        dp.append(nums[0])

        LIS = 1
        for i in range(1, len(nums)):
            if dp[-1] < nums[i]:
                dp.append(nums[i])
                LIS += 1
                continue

            idx = bisect_left(dp, nums[i])
            dp[idx] = nums[i]

        return LIS

    def lengthOfLISDP(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        result = 1

        for i in range(n):
            for j in range(i):
                # skip
                if nums[j] >= nums[i]:
                    continue

                dp[i] = max(dp[i], 1 + dp[j])
                result = max(result, dp[i])

        return result

    # memory O(n)
    def lengthOfLISTopDown(self, nums: List[int]) -> int:
        memo = {}

        def dfs(i):
            if (i) in memo:
                return memo[i]
            if i == len(nums):
                return 0

            res = 1

            for j in range(i + 1, len(nums)):
                if nums[j] > nums[i]:
                    res = max(res, 1 + dfs(j))

            memo[i] = res
            return res

        return dfs(0, -1)

    # memory O(n^2)
    def lengthOfLISTopDown(self, nums: List[int]) -> int:
        memo = {}

        def dfs(i, prev):
            if (i, prev) in memo:
                return memo[(i, prev)]
            if i == len(nums):
                return 0

            # skip
            res = dfs(i + 1, prev)
            # take
            if prev == -1 or nums[prev] < nums[i]:
                res = max(res, 1 + dfs(i + 1, i))

            memo[(i, prev)] = res
            return res

        return dfs(0, -1)


# Test helper
def test_length_of_lis():
    solution = Solution()

    # Test case 1: Example 1
    nums1 = [10, 9, 2, 5, 3, 7, 101, 18]
    expected1 = 4
    actual1 = solution.lengthOfLIS(nums1)
    print(f"{actual1} | {expected1}")

    # Test case 2: Example 2
    nums2 = [0, 1, 0, 3, 2, 3]
    expected2 = 4
    actual2 = solution.lengthOfLIS(nums2)
    print(f"{actual2} | {expected2}")

    # Test case 3: Example 3
    nums3 = [7, 7, 7, 7, 7, 7, 7]
    expected3 = 1
    actual3 = solution.lengthOfLIS(nums3)
    print(f"{actual3} | {expected3}")

    # Test case 4: Strictly increasing
    nums4 = [1, 2, 3, 4, 5]
    expected4 = 5
    actual4 = solution.lengthOfLIS(nums4)
    print(f"{actual4} | {expected4}")

    # Test case 5: Strictly decreasing
    nums5 = [5, 4, 3, 2, 1]
    expected5 = 1
    actual5 = solution.lengthOfLIS(nums5)
    print(f"{actual5} | {expected5}")

    # Test case 6: Mixed with duplicates
    nums6 = [1, 3, 2, 3, 1, 4]
    expected6 = 4  # e.g., [1,2,3,4]
    actual6 = solution.lengthOfLIS(nums6)
    print(f"{actual6} | {expected6}")


if __name__ == "__main__":
    test_length_of_lis()
